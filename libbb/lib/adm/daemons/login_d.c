// logind
// create by akuma@mud.com.cn
// 2009-10-04

void get_id(string arg,object ob);






// 当logon验证通过之后才让用户进入游戏世界，其实就是调用了用户中的某个函数
void enter_world(object ob)
{	
	write(" --|--	login_d.c中的enter_world()被调用。\n");


	ob->delete("login_temp");	//将标志给清除掉
	ob->setup();	
}

void logon(object ob)
{
	write(" --|--	login_d.c中的logon()被调用。\n");
	
	write("Welcome to my New mudlib\n");
	input_to("get_id", ob);		//
}

// ob是用户对象
void get_id(string arg,object ob)
{
	write(" --|--	login_d.c中的get_id()被调用。\n");

	ob->set("id", arg);
	enter_world(ob);
}
