# VEX-Freshmen-Group-1
Code Communication.

### 2025年同济大学VEX新生赛程序模板代码
  1. 修改项目名称：打开`.vscode/vex_project_settings.json`文件,修改`project`的`name`属性,修改烧录端口请使用插件的按键
  2. 模板给出基本代码框架,请根据每个文件的提示完成修改任务,主要修改`src`目录下的`main.cpp`、`pidControl.cpp`、`robot-config.cpp`,`include`目录下的`robot-config.h`文件和`tjulib-chassis/ordinary-chassis/ordistraight.hpp`文件,鼓励自己研究并编写定位系统
  3. 如果你需要自己实现一些其他方法,请在include文件夹中定义(参考地盘类实现方式),并记得在`tjulib.h`头文件中声明

## 🤝 团队协作完整指南

### 📥 1. 初次设置项目

**克隆项目到本地：**
```bash
git clone https://github.com/A1C1NY/VEX-Freshmen-Group-1.git
cd VEX-Freshmen-Group-1
```

**配置你的Git信息：**
```bash
git config --global user.name "你的姓名"
git config --global user.email "你的邮箱@example.com"
```

### 🌿 2. 分支管理和开发流程

**开始新功能开发：**
```bash
# 1. 确保在main分支上
git checkout main

# 2. 拉取最新代码
git pull origin main

# 3. 创建新的功能分支
git checkout -b feature/功能名称
# 例如：git checkout -b feature/autonomous-mode
# 例如：git checkout -b fix/motor-control-bug
```

**查看当前状态：**
```bash
# 查看当前分支
git branch

# 查看文件修改状态
git status

# 查看具体修改内容
git diff
```

### 💾 3. 提交和推送代码

**提交代码的完整流程：**
```bash
# 1. 查看修改了什么
git status

# 2. 添加要提交的文件
git add .                    # 添加所有修改的文件
# 或者
git add src/main.cpp         # 只添加特定文件

# 3. 提交更改
git commit -m "feat: 添加自动模式功能"

# 4. 推送到远程分支
git push origin feature/功能名称
```

### 🔄 4. 同步和合并代码

**定期同步main分支的最新代码：**
```bash
# 1. 切换到main分支
git checkout main

# 2. 拉取最新代码
git pull origin main

# 3. 切换回你的功能分支
git checkout feature/你的功能名称

# 4. 将main分支的更新合并到你的分支
git merge main
```

**如果遇到合并冲突：**
```bash
# 1. 手动编辑冲突文件，解决冲突标记
# 2. 添加解决冲突后的文件
git add 冲突文件名

# 3. 完成合并提交
git commit -m "resolve: 解决合并冲突"
```

### 📋 5. Pull Request 流程

**在GitHub网页上操作：**
1. 推送分支后，GitHub会显示 "Compare & pull request" 按钮
2. 点击按钮，填写PR信息：
   - 标题：简洁描述你的更改
   - 描述：详细说明你做了什么，为什么这样做
3. 选择审查者（团队成员）
4. 点击 "Create pull request"

**PR审查和合并：**
1. 等待团队成员审查代码
2. 根据反馈修改代码（如需要）
3. 审查通过后，维护者会合并分支
4. 合并后删除功能分支

### 🔄 6. 合并后的清理工作

**PR合并后的操作：**
```bash
# 1. 切换到main分支
git checkout main

# 2. 拉取最新代码（包含你的合并）
git pull origin main

# 3. 删除本地的功能分支
git branch -d feature/功能名称

# 4. 删除远程分支（可选）
git push origin --delete feature/功能名称
```

### 📚 7. 常用Git命令速查

**查看信息：**
```bash
git status              # 查看当前状态
git log --oneline -5     # 查看最近5次提交
git branch -a           # 查看所有分支
git remote -v           # 查看远程仓库
```

**撤销操作：**
```bash
git checkout -- 文件名   # 撤销未暂存的修改
git reset HEAD 文件名    # 从暂存区移除文件
git commit --amend      # 修改最后一次提交信息
```

**分支操作：**
```bash
git checkout 分支名      # 切换分支
git checkout -b 新分支名 # 创建并切换到新分支
git branch -d 分支名     # 删除本地分支
```

### 🚨 8. 重要注意事项

**开发规范：**
- ❌ **永远不要直接在main分支上开发**
- ✅ **始终创建新分支进行开发**
- ✅ **推送前先检查 `git status`**
- ✅ **提交前先查看 `git diff`**

**分支命名规范：**
- `feature/功能描述` - 新功能开发（如：feature/autonomous-mode）
- `fix/问题描述` - Bug修复（如：fix/motor-speed-issue）
- `docs/说明` - 文档更新（如：docs/add-setup-guide）
- `refactor/说明` - 代码重构（如：refactor/chassis-class）

**提交信息规范：**
- `feat: 新功能描述` - 添加新功能
- `fix: 修复问题描述` - 修复bug
- `docs: 文档更新` - 更新文档
- `style: 代码格式` - 代码格式调整
- `refactor: 重构说明` - 代码重构
- `test: 测试相关` - 添加或修改测试

**协作最佳实践：**
1. **每天开始工作前**：`git pull origin main`
2. **完成一个小功能就提交**：避免一次性提交太多更改
3. **写清楚的提交信息**：让别人能理解你做了什么
4. **定期推送代码**：避免代码丢失
5. **及时处理冲突**：不要积累太多冲突
6. **代码审查要认真**：帮助团队提高代码质量

**常见问题解决：**

**问题1：忘记创建分支，直接在main上开发了**
```bash
# 不要慌，可以这样补救：
git checkout -b feature/你的功能名  # 创建新分支
git checkout main                  # 回到main
git reset --hard origin/main      # 重置main到远程状态
git checkout feature/你的功能名    # 回到你的分支继续开发
```

**问题2：push被拒绝，提示需要先pull**
```bash
git pull origin main              # 先拉取最新代码
# 如果有冲突，解决冲突后：
git add .
git commit -m "resolve: 解决合并冲突"
git push origin 你的分支名
```

**问题3：想撤销最后一次提交**
```bash
git reset --soft HEAD~1           # 撤销提交但保留修改
# 或者
git reset --hard HEAD~1           # 撤销提交并丢弃修改（危险操作！）
```

### 📞 9. 团队协作流程示例

**场景：小明要添加自动模式功能**

```bash
# 1. 同步最新代码
git checkout main
git pull origin main

# 2. 创建功能分支
git checkout -b feature/autonomous-mode

# 3. 开发功能，修改文件...

# 4. 提交代码
git add .
git commit -m "feat: 添加自动模式基本框架"

# 5. 推送分支
git push origin feature/autonomous-mode

# 6. 在GitHub上创建Pull Request

# 7. 等待审查和合并

# 8. 合并后清理
git checkout main
git pull origin main
git branch -d feature/autonomous-mode
```

**记住：Git协作的核心是沟通！遇到问题及时和团队沟通。**

## 📁 项目结构
```
├── include/                 # 头文件目录
│   ├── tjulib-chassis/     # 底盘控制相关
│   ├── tjulib-position/    # 定位系统相关
│   └── *.h                 # 其他头文件
├── src/                    # 源代码目录
│   ├── main.cpp           # 主程序文件
│   └── *.cpp              # 其他源文件
├── vex/                   # VEX相关配置
└── .vscode/               # VS Code配置
```

## 🚀 快速开始
1. 克隆项目到本地
2. 使用VEX Code打开项目
3. 配置机器人硬件连接
4. 编译并上传到机器人
