 # mudos-efun
============




Note:
----

实验环境：Ubuntu 14.04 LTS 64位

mongo c driver : mongoc-1.0 (内置bson-1.0)

需求：编写一套与mongodb交互的efun供LPC使用。

mudos版本：v22.4b14

注：文档较少，全靠热情在折腾。





mudos的正常编译
----

测试环境：
` ./build.MudOS `

编译：
` make `
` make #没错，需要make两次才行。 `

安装：
` make install `


目录结构：
---------

` ./ `	根目录下的文件是一些mudos的基础文件，比如支持LPC的mapping等文件。

` testsuite/ `	这是此本版mudos自带的一个mudlib。

` packages/ `	扩展的efun，会随着mudos一块编译进去driver,我一般就在这实现efun了。

` obj/ `	编译mudos的过程所产生的临时文件，比如只编译没连接的.o文件。

` bin/ `	make install命令会将编译出来的可执行文件放在这里，如果不执行make install，可执行文件就只存在于根目录下。

` libbb/ `	这是本人实现的一个mudlib，用于测试efun是否可以正常使用的。

` libs `	这是mongo c driver的头文件，应该是不需要的，先不折腾了，暂时放着。

其他的基本可以暂时不用理。








