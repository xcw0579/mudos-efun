
#include "../std.h"





#ifdef LATTICE

#include "/comm.h"
#include "/lpc_incl.h"

#else

#include "../lpc_incl.h"
#include "../comm.h"
#include "../efun_protos.h"

#endif




/*
 * 本文件以及myefun_spec.c仅用于测试efun的编译流程。
 * 测试已通过，在此作废。
 *
 *
 * */









#ifdef F_HELLO_WORLD
void 
f_hello_world(void) /*有些EFUN都带PROT什么的，别理它，俺们操作系统认识不带PROT的。*/
{
	char * res;
	int type = sp->u.number;
	pop_n_elems(st_num_arg);
	
	switch(type)
	{
		case 1: res = "hello world, I am the first type."; break;
		case 2: res = "hello world, I am the second type."; break;
		default : res = "hello world, I am nothing.";
	}
	copy_and_push_string(res);
}
#endif
