//处理用户的请求，注意这里是个LPC文件吖

inherit F_DBASE;	// 这是个mapping，用于存储用户的数据
int setup();


void create()
{
	write(" --|--	user.c中的create()被调用。\n");
	//setup();
	return ;
}



// 操作用户数据
int setup()
{	
	write(" --|--	user.c中set_up()被调用。\n");


	log_file("user", sprintf("%O setup at %s\n", this_object(), ctime(time())));
	set_living_name( query("id") );	// 新增的什么？
	enable_commands();
	add_action("cmd_hook", "", 1);	// 将钩子挂在obj身上，一旦有指令来，就找钩子。

	return 1;
}



// 钩子函数
int cmd_hook(string arg)
{
	string verb = query_verb();	//得到最近的一个指令名称
	
	write(" --|--	user.c中的cmd_hook()被调用。\n");
	
	// 注意文件就是对象，所以CMD_D是对象。	
	return CMD_D->do_cmd(this_object(), verb, arg);	
}



// 自动被调用?
void logon()
{
	write(" --|--	user.c中的logon()被调用。\n");

	call_out("login_timeout", 1);
	set("login_temp", 1);	// 操作用户数据
	LOGIN_D->logon(this_object());
}



void login_timeout()
{
	write(" --|--	user.c中的login_timeout()被调用。\n");

	if( query("login_temp") )
		destruct( this_object() );	//析构用户对象
	return;
}







// 所有的用户输入都将先进入此函数
/*
string process_input(string arg)
{
	write(" --|--	user.c中的process_input()被调用。\n");
	
	
    write(arg+"\n");
    return "";
}
*/

