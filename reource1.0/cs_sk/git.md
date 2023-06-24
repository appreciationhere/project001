## 本地git库管理
创建管理库   git init;
添加文件到待提交区 git add text1.txt text2.txt;
提交代码   git commit -m "add two tex";
查看仓库当前状况   git status;
查看某个文件状态   git diff  readme.txt;
查看日志  git log (--pretty=oneline);
回退  git reset --hard '版本号';
查看历史回退命令   git reflog;
撤销工作区内容, 还原到最近的缓冲区的内容或者提交的内容:  git checkout -- readme.txt;
撤销缓存区内容, 重新放回工作区: git reset HEAD readme.txt;
删除文件: git rm readme.txt, git commit -m "remove readme.txt";
## git与git传输:
1. ssh-keygen -t rsa -C "youremail@example.com"
2. 得到.ssh文件夹, id_rsa是私匙, id_rsa.pub是公匙;
3. github通过ssh添加公匙;
4. 修改分支名字 git branch -M main; 
5. 关联远程库 git remote add origin git@github.com:appreciationhere/project001.git;
6. 内容推送到远程库 git push -u origin main;
7. 查看远程库信息 git remote -v;
8. 删除远程库 git remote rm origin;
9. 克隆代码到本地 git clone git@github.com:appreciationhere/project001.git;
## 分支和合并
分支的作用是提交已经写了一部分的代码, 还不能上线;
不同分支的提交都是通过指针完成的, 所以速度很快, 每提交一次, 当前分支的指针就前移一次;
创建并切换工作区 git checkout -b(switch -c) dev == git branch dev; git checkout(switch) dev("切换到存在的工作区");
查看当前所有分支 git branch;
合并指定分支到当前分支 git merge (--no-ff) (-m "first merge")dev;
删除分支 git branch -d  dev;
分支合并图 git log --graph;
开发一个新feature，最好新建一个分支,如果要丢弃一个没有被合并过的分支，可以通过git branch -D强行删除。
rebase操作可以把本地未push的分叉提交历史整理成直线,rebase的目的是使得我们在查看历史提交的变化时更容易，因为分叉的提交需要三方对比。git rebase;
## 修改bug分支
1. 需要紧急修改bug分支时, 如果当前的工作区内容还没写完不能提交可以隐藏当前工作区内容 git stash;
2. 确定bug的所在分支, 设为master, 设修改的文件为101, git checkout -b issue-101;
3. git add readme.txt; git commit -m "fix bug 101";
4. git switch master; git merge --no-ff -m "merged bug fix 101" issue-101;
5. 查看工作现场列表 git stash list; 恢复工作现场 git stash apply 'stash@{0}';
6. 删除 git stash drop; 删除当前恢复最近 git stash pop;
7. 复制一个特定的提交到当前分支 git cherry-pick '4c805e2'
## 多人协助工作模式
1. 每人在自己的dev分支上推送修改文件 git push origin dev;
2. 推送失败就是 git pull, 解决冲突并在本地提交;
3. 如果git pull提示no tracking information，则说明本地分支和远程分支的链接关系没有创建，用命令git branch --set-upstream-to <branch-name> origin/<branch-name>;
4. 没有冲突或者解决掉冲突后，再用git push origin <branch-name>;
## 标签管理
tag就是一个让人容易记住的有意义的名字，它跟某个commit绑在一起;
1. 切换到需要打标签的分支上;
2. 打标签,默认标签是打在最新提交的commit上的 git tag 'v1.0' (-m "first tag") ('id');
3. 查看所有标签 git tag;
4. 查看标签信息 git show 'v1.0';
5. 删除 git tag -d 'v0.1'; 远程删除 git push origin :refs/tags/'v1.0'
6. 推送标签到远程 git push origin 'v1.0'; 推送全部标签 git push origin --tags