
int main(object me, string arg)
{

	string str;


	//write( hello_world(25)+"\n" );
	
	write(" --|--	test.c中main()被调用。\n");



	mongoc_init();
	str=testing();
	write("测试结果："+str);
	mongoc_cleanup();
	
	// write("in cmd test: arg="+arg+"\n");

	return 1;
}
