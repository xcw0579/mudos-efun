
// 这是个命令对象，挂在另一个对象身上，如果不销毁，是不会再次调用create的。
void create()
{
	write(" --|--	cmd_d.c中create()被调用。\n");

	return ;
}

int do_cmd(object me, string verb, string arg)
{
	write(" --|--	cmd_d.c中do_cmd()被调用。\n");

	//	调用在usr文件夹下对应的文件。
	return ("/cmds/usr/"+verb)->main(me, arg);
}
