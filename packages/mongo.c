
/*
 * 先不考虑出错的问题
 * 简单实现连接、关闭、增删查改。
 * 直接使用c driver的接口，只不过将一些基础类型有变动 
 * 只能有一个连接，这样就不用返回了。
 * 实现中不能使用到自己提供的接口，只能调用mongo c driver的接口。
 * */
#include "mongo.h"



mongoc_client_t * client;		/* 全局的一个连接 */
mongoc_database_t *database;	/* 当前数据库 */
mongoc_collection_t *collection;/* 当前集合 */


/*
 * 参数：1个  类型：string
 * 返回：无
 * */
/*
#ifdef F_MONGOC_CLIENT_GET_DATABASE
void
f_mongoc_client_get_database (void)
{
	    int num_arg = st_num_arg;	
	svalue_t *arg;	

	if( num_arg!=1 )	
	{
		error(" the number of arguments is wrong。\n");
	}
	if( !(sp->type &T_STRING)  )
	{
		bad_arg(1, F_MONGOC_CLIENT_GET_DATABASE);	
	}

	//可能已经连接了其他的database，释放
	if( database )
	{
		mongoc_database_destroy(database);
		database=NULL;	
	}

	database=mongoc_client_get_database(client, sp->u.string );
}
#endif
*/


/*
 * 参数：无
 * 返回：无
 * */
/*
#ifdef F_MONGOC_DATABASE_DESTROY
void
f_mongoc_database_destroy (void)
{
	mongoc_database_destroy( database );

}
#endif
*/


/*
 * 参数：无
 * 返回：无
 */	
/*
#ifdef F_MONGOC_CLIENT_DESTROY
void
f_mongoc_client_destroy (void)
{
	if( client )
	{
		mongoc_client_destroy( client );
	}
}
#endif
*/



/*
#ifdef F_MONGOC_CLIENT_NEW1
void
f_mongoc_client_new1 (void)	
{




}
#endif
*/








/* 
 * 创建一个新的连接，暂时是全局的。
 */
#ifdef F_MONGOC_CLIENT_NEW
void
f_mongoc_client_new (void)	
{
	/*
	 * 参数：1个  类型：string
	 * 返回：无
	 * */
    int num_arg = st_num_arg;	
	svalue_t *arg;	

	if( num_arg!=1 )	
	{
		error(" the number of arguments is wrong。\n");
	}
	if( !(sp->type &T_STRING)  )
	{
		bad_arg(1, F_MONGOC_CLIENT_NEW);	
	}

	client=mongoc_client_new( sp->u.string );	
	pop_n_elems( num_arg );	
}
#endif




/*
 * 做一些初始化工作，包括调用mongoc_init()。
 * */
#ifdef F_MONGOC_INIT
void
f_mongoc_init (void)
{
	/*
	 * 无参数，无返回
	 * */

	client=NULL;

	mongoc_init();
}
#endif


/*
 * 做一些善后工作，包括调用mongoc_cleanup()
 * */
#ifdef F_MONGOC_CLEANUP
void
f_mongoc_cleanup (void)
{
	/*
	 * 参数：无
	 * 返回：无
	 * */
	//	write("我证明调用成功。");
	if( client )
	{
		mongoc_client_destroy( client );
	}

	mongoc_cleanup();
}
#endif















#ifdef F_TESTING
void
f_testing (void)
{
	mongoc_database_t    *database;
	mongoc_collection_t  *collection;
	bson_t               *command, reply;
	bson_error_t          error;

	char	*str;
	bool	retval;
	client=mongoc_client_new("mongodb://localhost:27017");
	database = mongoc_client_get_database (client, "db_name");	//连接数据库
	collection = mongoc_client_get_collection (client, "db_name", "coll_name");// 获取集合 
	
	command = BCON_NEW ("ping", BCON_INT32 (1));
	retval = mongoc_client_command_simple (client, "another", command, NULL, &reply, &error); 

	if (!retval) {
		//fprintf (stderr, "%s\n", error.message); 
		str="wrong op。";
		copy_and_push_string(str);

		mongoc_collection_destroy(collection);
		mongoc_database_destroy(database);
		
		return ;
	}

	str = bson_as_json (&reply, NULL);	//将command的结果，bson转成json，之后就变成string可以输出
	copy_and_push_string(str);

	mongoc_collection_destroy(collection);
	mongoc_database_destroy(database);
	
	bson_destroy (&reply);
	bson_destroy (command);
	bson_free (str);

}
#endif



