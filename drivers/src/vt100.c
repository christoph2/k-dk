
#include "vt100.h"


#if 0
/* Philo5 */
"/---------\"
"|         |"
"|    |    |"        
"|         |"
"\---------/"


"/---------\"
"|         |"
"|   | |   |"        
"|         |"
"\---------/"
 
#endif

#if 0
+-------------------------------+
|                               |
|                               |
|                               |
|                               |
|                               |
+-------------------------------+
#endif

void VT100_CUU(uint8 distance,char *buf)  /* Cursor Up */
{
    /*  <ESC>[ {Pn} A */
    Utl_StrCpy(buf,VT100_CSI);
    Utl_Itoa(distance,10,buf+2);
    Utl_StrCat(buf,"A");
}

void VT100_CUD(uint8 distance,char *buf)  /* Cursor Down */
{
    /*  <ESC>[ {Pn} B */
    Utl_StrCpy(buf,VT100_CSI);
    Utl_Itoa(distance,10,buf+2);
    Utl_StrCat(buf,"B");
}

void VT100_CUF(uint8 distance,char *buf)  /* Cursor Foreward */
{
    /*  <ESC>[ {Pn} C */
    Utl_StrCpy(buf,VT100_CSI);
    Utl_Itoa(distance,10,buf+2);
    Utl_StrCat(buf,"C");
}
            
void VT100_CUB(uint8 distance,char *buf)  /* Cursor Backward */
{
    /*  <ESC>[ {Pn} D */
    Utl_StrCpy(buf,VT100_CSI);
    Utl_Itoa(distance,10,buf+2);
    Utl_StrCat(buf,"D");
}

void VT100_CUP(uint8 line,uint8 column,char *buf) /* Cursor Position */
{
    uint8 len;
    /*  <ESC>[ {Pn} ; {Pn} H */
    /*
        The CUP sequence moves the curor to the position specified by the
        parameters.  The first parameter specifies the line, and the second
        specifies the column.  A value of zero for either line or column moves
        the cursor to the first line or column in the display.  The default
        string (<ESC>H) homes the cursor.  In the VT100, this command behaves
        identically to it's format effector counterpart, HVP.

        The numbering of the lines depends upon the state of the Origin Mode
        (DECOM).  Editor Function.
    */
    Utl_StrCpy(buf,VT100_CSI);
    Utl_Itoa(line,10,buf+2);
    Utl_StrCat(buf,";");
    len=Utl_StrLen(buf);
    Utl_Itoa(column,10,buf+len);
    Utl_StrCat(buf,"H");
}


void VT100_SGR(const uint8 *attrs,uint8 len,char *buf)
{
    uint8 pos;
/*
        <ESC>[ {Ps} ; {Ps} m

        Invoke the graphic rendition specified by the parameter(s).  All
        following characters transmitted to the VT100 are rendered according
        to the parameter(s) until the next occurrence of an SGR.  Format
        Effector.

        Parameter       Meaning
        ---------------------------------------------------------------
            0           Attributes Off
            1           Bold or increased intensity
            4           Underscore
            5           Blink
            7           Negative (reverse) image

        All other parameter values are ignored.

        Without the Advanced Video Option, only one type of character attribute
        is possible, as determined by the cursor selection; in that case
        specifying either underscore or reverse will activate the currently
        selected attribute.

        [Update:  DP6429 defines parameters in the 30-37 range to change
        foreground color and in the 40-47 range to change background.]
*/    
    Utl_StrCpy(buf,VT100_CSI);

    pos=2;
    while (len--) {
        Utl_Itoa(*(attrs++),10,buf+pos);
        if (len>0) {
            Utl_StrCat(buf,";");
        }
        pos=Utl_StrLen(buf);
    }
    
    Utl_StrCat(buf,"m");
}

void VT100_CHOME(char *buf)
{
   /*  <ESC>[  H */
    Utl_StrCpy(buf,VT100_CSI);
    Utl_StrCat(buf,"H");    
}

void VT100_HVP(uint8 line,uint8 column,char *buf)
{
    uint8 len;
/*    
        <ESC>[ {Pn} ; {Pn} f

        Moves the cursor to the position specified by the parameters.  The
        first parameter specifies the line, and the second specifies the
        column.  A parameter of 0 or 1 causes the active position to move to
        the first line or column in the display.  In the VT100, this control
        behaves identically with it's editor counterpart, CUP.  The numbering
        of hte lines depends upon the state of the Origin Mode (DECOM).  Format
        Effector.
*/            
    Utl_StrCpy(buf,VT100_CSI);
    Utl_Itoa(line,10,buf+2);
    Utl_StrCat(buf,";");
    len=Utl_StrLen(buf);
    Utl_Itoa(column,10,buf+len);
    Utl_StrCat(buf,"f");    
}

void VT100_Send(const SCI_ConfigType *Cfg,const char *buf)
{
    uint8 len=Utl_StrLen(buf);

    SCI_SendBuffer(Cfg,(uint8*)buf,len);
    WAIT_FOR(SCI_TxReady(SCI0));   /* Blocking, to prevent 'buf' from being overwritten. */
}

/*
**
**  Highlevel-Functions.
**
*/

static char VT100_TxBuffer[VT100_BUFFER_LEN];

void VT100_CursorUp(const SCI_ConfigType *Cfg,uint8 distance)
{
    VT100_CUU(distance,VT100_TxBuffer);
    VT100_Send(Cfg,VT100_TxBuffer);
}

void VT100_CursorDown(const SCI_ConfigType *Cfg,uint8 distance)
{
    VT100_CUD(distance,VT100_TxBuffer);
    VT100_Send(Cfg,VT100_TxBuffer);
}

void VT100_CursorRight(const SCI_ConfigType *Cfg,uint8 distance)
{
    VT100_CUF(distance,VT100_TxBuffer);
    VT100_Send(Cfg,VT100_TxBuffer);    
}

void VT100_CursorLeft(const SCI_ConfigType *Cfg,uint8 distance)
{
    VT100_CUB(distance,VT100_TxBuffer);
    VT100_Send(Cfg,VT100_TxBuffer);
}

void VT100_CursorPosition(const SCI_ConfigType *Cfg,uint8 line,uint8 column)
{
    VT100_HVP(line,column,VT100_TxBuffer);
    VT100_Send(Cfg,VT100_TxBuffer);    
}

void VT100_CursorHome(const SCI_ConfigType *Cfg)
{
    VT100_CHOME(VT100_TxBuffer);
    VT100_Send(Cfg,VT100_TxBuffer);
}


void VT100_CharAttributes(const SCI_ConfigType *Cfg,const uint8 *attrs,uint8 len)
{
    VT100_SGR(attrs,len,VT100_TxBuffer);
    VT100_Send(Cfg,VT100_TxBuffer);
}

/*
**
**  todo: 'WriteString', 'WriteInteger' etc.
**
*/

/*
**
**  Receive-Handler.
**
*/

enum {START,ESC,CSI};

void VT100_RxHandler(char ch)
{
    static uint8 state=START;
    
    if (ch==ASCII_ESC) {
        if (state==START) {
            state=ESC;
        } else {
            state=START;
        }
    }

    switch (state) {
        case ESC:
            if (ch=='[') {
                state=CSI;
            } else {
            
            }
            break;
        case CSI:
          /*
          **    HOME: ESC[H
          **    END: ESC[K
          **
          */
            break;
        case START:
            break;
        default:
            ASSERT(FALSE);
    }
}

