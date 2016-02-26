
/*
 * 先不考虑出错的问题
 * 简单实现连接、关闭、增删查改。
 * 直接使用c driver的接口，只不过将一些基础类型有变动 
 * 只能有一个连接，这样就不用返回了。
 * */






/*#include "mongo.h"*/
/*
#include "/home/xiao/libbson-1.0/bson.h"
#include "/home/xiao/libbson-1.0/bcon.h"
#include "/home/xiao/libmongoc-1.0/mongoc.h"
#include "../libs/libbson/bson.h"
#include "../libs/libbson/bcon.h"
#include "../libs/libmongoc/mongoc.h"


#include <bson.h>
#include <bcon.h>
#include <mongoc.h>
*/

#include "bson.h"
#include "bcon.h"
#include "mongoc.h"


#include "../std.h"
#include "../md.h"
#include "../master.h"
#include "../lpc_incl.h"
#include "../mapping.h"
#include "../comm.h"
#include "../file_incl.h"
#include "../file.h"
#include "../object.h"
#include "../eoperators.h"
#include "../backend.h"
#include "../swap.h"






struct mongoc_client * client;		/* 全局的一个连接 */




/*
 * 做一些初始化工作，包括调用mongoc_init()。
 * */
#ifdef F_MONGOC_INIT_S
void
f_mongoc_init_s (void)
{
	/*
	 * 无参数，无返回
	 * */

	client=NULL;

	mongoc_init();
	mongoc_cleanup();
}
#endif
/*
 * 做一些善后工作，包括调用mongoc_cleanup()
 * */
#ifdef F_MONGOC_CLEANUP_S
void
f_mongoc_cleanup_s (void)
{
	/*
	 * 参数：1个  类型：string
	 * */

	if( client )
	{
		/*mongoc_client_destroy( client );*/
	}
	/*mongoc_cleanup();*/
}
#endif


/* 参考：http://api.mongodb.org/c/current/mongoc_client_new.tml
 * 创建一个新的连接
 */
/*
void
f_mongoc_client_new (void)	
{
*/
	/*
	 * 参数：1个  类型：string
	 * */
/*
    int num_arg = st_num_arg;	
	svalue_t *arg;		

	if( num_arg==0 || num_arg>1 )	
	{
		error("the argument is required。\n");
	}
	if( !(sp->type &T_STRING)  )
	{
		bad_arg(1, F_MONGOC_CLIENT_NEW);	
	}

	client=mongoc_client_new( sp->u.string );	
	pop_n_elements( num_arg );	
}

*/

/*
void
f_test (void)
{
	mongoc_database_t    *database;
	mongoc_collection_t  *collection;
	bson_t               *command, reply;
	bson_error_t          error;
	char                 *str;
	bool                  retval;

	database = mongoc_client_get_database (client, "db_name");
	collection = mongoc_client_get_collection (client, "db_name", "coll_name");

	command = BCON_NEW ("ping", BCON_INT32 (1));	//这是bson对象。
	retval = mongoc_client_command_simple (client, "another", command, NULL, &reply, &error);

	if (!retval) {
		fprintf (stderr, "%s\n", error.message); 
		return EXIT_FAILURE;
	}

	str = bson_as_json (&reply, NULL);	//将command的结果，bson转成json，之后就变成string可以输出
	printf ("%s\n", str);

	return ;
}




*/





