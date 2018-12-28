# GIT-笔记

## 1. 创建库

- 创建新的文件/文件夹

	```mkdir <filename>```

- 移动到某个位置

	```cd sample disk/sample folder```

- 将当前所在文件夹添加到git管理下（初始化）

	```git init```

- 将处于工作区的某个文件/对文件的修改添加到git的暂存区中

	```git add <filename>```

- 将暂存区文件/修改提交到git中

	```git commit -m "Your commit"```

	注意，该命令会将暂存区的所有待提交修改提交到git，若只提交一个，加上```<filename>```

## 2. git版本管理

重点是理解git是通过一个指针HEAD来寻找所有提交过的修改的，所以版本管理就是基于这个指针的移动

- 查看当前库的状态

	```git status```

- 查看文件库中文件与未提交修改的区别

	```git diff```

- 查看当前日志

	```git log```

- 查看库日志

	```git reflog```

- 回到提交过的的某个版本

	```git reset -- hard HEAD^/HEAD~10/commit id```

- 删除文件

	```rm <filename>```

- 恢复文件

	```git checkout <filename>```

	相当于将库中保存的文件还原

## 3. 远程仓库

- 创建ssh key

	在git库下```ssh-keyge -t rsa -C "email@email.com"```

	之后打开.pub文件复制key到github

- 将本地库与远程库连接

	```git remote add origin git@github.com:XYPB/<libname>.git```

- 将分支内容推送到库中

	```git push (-u) origin <brname>```

- 克隆库

	```git clone git@github.com:XYPB/<libname>.git```

	这种方式是通过ssh协议克隆，速度快，方便

- 查看远程库信息

	```git remote (-v)```

- 从远程库中抓取分支

	克隆库时会出现只克隆了master的情况
	
	- 此时需要在本地创建同名的dev分支

		```git checkout -b <本地brname> <远端brname>```

	- 并将该分支与远端分支链接

		```git branch --set-upstream-to=<远端brname> <本地brname>```

	- 之后再抓取该远端分支上的最新库

		```git pull```

	- 在推送本地更新到远端

## 4. 分支管理

所谓分支，就是创建一个不同于master指针的新的指针

- 查看当前分支

	```git branch```

- 创建新分支

	- ```git branch <name>```

	- ```git checkout -b <name>```

- 切换分支

	```git checkout <name>```

- 合并某分支到当前分支

	```git merge <name>```

- 删除分支

	```git branch -d <name>```

	将-d参数替换为-D以强制删除未合并分支

- 以图像形式查看分支

	```git log --graph```

- 保存了分支信息的合并

	```git --bo-ff -m "Your commit"```

- 保存当前分支下的工作区&暂存区&库内容

	```git stash```

- 查看当前分支中保存的工作区

	```git stash list```

- 恢复某个工作区

	- ```git apply <stashname>```

	- 同时删除该stash```git stash pop <stashname>```

- 删除某个stash

	```git stash drop <stashname>```

- 分支整理（变直！）

	```git rebase```

- 为当前分支的某个commit打上标签

	```git tag <tagname> (<commit id>)```

	加-d参数以删除tag

	注意，该tag是关于commit而非branch的

- 根据tag查找commit

	```git show <tagname>```

- 推送tag至远端

	```git push origin <tagname>```