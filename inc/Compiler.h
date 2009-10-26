/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de,
 *                                      cpu12.gems@googlemail.com>
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
#if !defined(__COMPILER_H)
#define	__COMPILER_H

/* Symbol: _<COMPILERNAME>_C_<PLATFORMNAME>_
**	"can be used to switch bewtween different
**	Implementations f. different Compilers, e.g.
**		- inline assembler fragments in drivers.
**		- special pragmas for memory alignment control
**		- localizqation of function calls.
**		- adaptions to memory modells."
**
** _IMAGECRAFT_C_CPU12_
** _METROWERKS_C_CPU12_
*/

#define	AUTOMATIC	/* shall be provided as empty definition. */
#define	_STATIC_	static
#define	NULL_PTR	((void*)0)

#define	FUNC(rettype,memclass)

/*
 Example (Cosmic, S12X):
 #define	FUNC(rettype,memclass)	memclass rettype
 FUNC(void,@near) ExampleFunction(void);
*/

#define	P2VAR(ptrtype,memclass,ptrclass)
/*
	Example (Metrowerks, S12X)
	#define	P2VAR(ptrtype,memclass,ptrclass) \
	ptrclass ptrtyppe * memclass
	
	#define SPI_APLL_DATA	@far
	#define SPI_VAR_FAST	@near
	
	P2VAR(uint8,SPI_VAR_FAST,SPI_APPL_DATA) Spi_FastPointerToApllData
*/



/*
"For each Compiler and Platform an own Compiler
Abstraction has to be provided".
*/

/*
	NEAR-FUNCTION-Deklarationen:
	----------------------------
	Cosmic:
	@near void MyNearFunction(void);
	
	Metrowerks:
	void __near MyNearFunction(void);
	
	IAR:
	void __non_banked MyNearFunction(void);
	
	Imagecraft:
	#pragma nonpaged_function MyNearFunction
	void MyNearFunction(void);
	
	FAR-FUNCTION-Deklarationen:
	---------------------------
	Cosmic:
	@near void MyFarFunction(void);

	Metrowerks:
	void __far MyFarFunction(void);

	IAR:
	void __banked MyFarFunction(void);

	Imagecraft:
	#pragma paged_function MyFarFunction
	void MyFarFunction(void);

	NEAR-POINTER(Var./RAM)-Deklarationen:
	-------------------------------------	
	Cosmic:
	@near uint8* MyNearPointer;
	
	Metrowerks:
	uint8* __near MyNearPointer;
	
	IAR:
	uint8* __data16 MyNearPointer;
	
	Imagecraft:
	uint8 *MyNearPointer;

	FAR-POINTER(Var./RAM)-Deklarationen:  	
	------------------------------------
	Cosmic:
	@far uint8* MyFarPointer;
	
	Metrowerks:
	uint8* __far MyFarPointer;
	
	IAR:
	n/a
	
	Imagecraft:
	uint8* MyFarPointer;
		
	
*/

#endif	/*  __COMPILER_H  */
