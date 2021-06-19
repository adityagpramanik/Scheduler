# Start contributing to Scheduler

You can start contributing by following the steps below:

 - [Fork](#fork)
 - [Save locally](#local)
 - [Create separate branch](#issue)
 - [Make changes](#make)
 - [Push it your cloud repo](#push)
 - [Pull](#pull)

## <a name="fork"></a> Fork
Click on the fork button available on the top right corner of this page.
It will create a copy of the parent repo in your account.

## <a name="local"></a> Save Locally
Heading to the **[download code button][down]** to download the repo in the *zip* format into your local machine.

*or*

You can run the following command from the terminal
```shell
git clone https://github.com/adityagpramanik/Scheduler.git
```

## <a name="issue"></a> Create Seperate Branch
Before start coding, it's always better to create a seperate branch with an appropriate name.

You can do so by using the built-in option provided in any IDE like **Atom** or **VS Code**.

*or*

You can run the following command to create a Branch
```shell
git checkout -b name_of_your_new_branch
```

You can also see all the branches created so far by running the below command :
```shell
git branch -a
```

## <a name="make"></a> Make Changes
You can use any IDE/Text Editor which supports **git & GitHub** functionality, such as **Atom, VS Code etc**.
Make changes to any file or add new file in the repo and then stage them with the editor. or by running the command in shell:


```shell
git add file_name
```

You can get the snapshot of what changes have been made by:
```shell
git diff
```
## <a name="make"></a> Push it Your Cloud Repo
Pushing is sharing the edited or new file to the cloud repo

You can easily stage and push the changed file with the editor or by adding following code to your terminal:
```shell
git add file_name
git commit -m "descriptive message"
git push
```

**Note: Your commit message should be concise for small changes like typo error or commenting but should be descriptive for major changes such as feature add or bug-fix**

## <a name="pull"></a> Pull from Remote Repo
Pulling is downloading the files updated by other contributors from the remote repo.

You can pull the files by just running:
```shell
git pull
```

*check out **[Contributing Guidelines][contri]**.*


`**Happy Coding (\*-\*)**`

[github]: https://github.com/adityagpramanik/Scheduler
[contri]: /Contributing.md
[contri]: /Contributing.md
[down]: https://github.com/adityagpramanik/Scheduler/archive/master.zip
