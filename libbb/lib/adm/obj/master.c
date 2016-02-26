// master ob of my new mudlib
// core of a mudlib
// create by akuma@mud.com.cn
// 2009-08-08

/*
*	除了create()，其他的函数都是master apply，提供给mudos调用的
*	
*/



// create of an object	初始化用的
void create()
{
	write(" --|--	master.c中的create()被调用。\n");

	return;
}




// master apply::crash  崩溃时调用
// called when driver crashed	
// output crash log if we can catch some info how it crashed
void crash(string error, object command_giver, object current_object)
{
    int i, kk, ii, size;
    object ob;
    mixed userlist, pets;
    mixed sql_str, file;
    
    write(" --|--	master.c中的crash()被调用。\n");
    
    
    assure_file("/log/CRASH");
    write_file("/log/CRASH", sprintf("%s:Driver crashed.\nerror=%s\ncommand_giver=%O\ncurrent_object=%O\n\n", ctime(time()), error, command_giver, current_object));
    
    return;
}

//master apply::log_error	
//auto log compiling error
void log_error(string file, string message)
{
	write(" --|--	master.c中的log_error()被调用。\n");


	catch(write_file("/log/LOG", sprintf("%s:%s\n%s\n\n", ctime(time()), file, message)));
	return;
}



//master apply::errr_handler
//auto log runtime error
void error_handler(mapping error, int caught)
{
	int i, s;
	string res;
	mixed trace, tmp;
	
	write(" --|--	master.c中的error_handler()被调用。\n");
	
	
	if (!mapp(error))
		return;

	log_file("error_handler", sprintf("Runtime Error at %s:\n", ctime(time())));
	res = (caught) ? "错误讯息被拦截: " : "错误";
	res = sprintf("%s\n执行时段错误：%s\n程式：%s 第 %i 行\n物件: %O\n对象：%O\n",
		res, 
		error["error"],
		error["program"], 
		error["line"],
		error["object"],
		this_player()
	);

	for (i=0, s = sizeof(error["trace"]); i < s; i++)
		res = sprintf("%s呼叫来自：%s 的 %s() 第 %i 行，物件： %O\n",
			res,
			error["trace"][i]["program"],
			error["trace"][i]["function"],
			error["trace"][i]["line"],
			error["trace"][i]["object"]
		);
	
	log_file("error_handler", res + "\n");
	

}
	
	
	
//master apply::get_root_uid
//get root uid
string get_root_uid()
{

	write(" --|--	master.c中的get_root_uid()被调用。\n");
	return "Root";
}



//master apply::get_bb_uid
//get backbone uid
string get_bb_uid()
{

	write(" --|--	master.c中的get_bb_uid()被调用。\n");
	return "Backbone";
}



//master apply::connect		处理用户连接
//notice: this apply is called by new login
//and return an object		返回一个对象
//normally it should be "login_ob"	本来应该是个login对象
//but now,we just use user_ob instead 但是目前用user对象顶替
object connect()
{
	write(" --|--	master.c中的connect()被调用。\n");

	log_file("new_user_login", time()+"\n");
	return new("/obj/user.c");	// 返回一个新的对象与连线对象绑定
}


string creator_file()
{
	write(" --|--	master.c中的creator_file()被调用。\n");
	
	return "Root";
}



//master apply::epilog	提交那些需要预加载的文件
//return file list to preload
string *epilog(int load_empty)
{
	write(" --|--	master.c中的epilog()被调用。\n\n");

    return  ({});
}

//master apply::preload 当一个mudlib正在启动时预加载,所载文件由epilog列出
//preload file when a mudlib is starting
void preload(string file)
{

	string err, str;
	write(" --|--	master.c中的preload()被调用。\n");


	if (file_size(file) == -1)
		return;

	err = catch(load_object(file));
	
	if (err)
		str = sprintf("预载入：%s发生错误：%s。\n", file, err);
	else
		str = sprintf("预载入：%s成功。\n", file);
	
	write(str);
	return;
}

