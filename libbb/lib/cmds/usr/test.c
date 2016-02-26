
int main(object me, string arg)
{

	//string str;


	//write( hello_world(25)+"\n" );
	
	write(" --|--	test.c中main()被调用。\n");


	mongoc_init();
	mongoc_client_new("mongodb://localhost:27017");
	mongoc_client_new1();
	//mongoc_client_get_database("db_name");
	
	write("获取数据库完毕。\n");


	//mongoc_database_destroy();
	//mongoc_client_destroy();
	mongoc_cleanup();

	return 1;
}
