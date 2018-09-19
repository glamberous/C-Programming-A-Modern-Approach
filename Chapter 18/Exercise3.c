/* List the storage duration (static or automatic), scope (block or file),
and linkage (internal, external, or none) of each variable and parameter
in the following file: */

extern float a;

void f(register double b)
{
	static int c;
	auto char d;
}

//a) Storage Duration: static  ; Scope: file  ; linkage: ?

//b) Storage Duration: automatic  ; Scope: block  ; linkage: none

//c) Storage Duration: static  ; Scope: file   ; linkage: internal

//d) Storage Duration: automatic  ; Scope: block   ; linkage: none
