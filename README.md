# VEX-Freshmen-Group-1
Code Communication.

### 2025年同济大学VEX新生赛程序模板代码
  1. 修改项目名称：打开`.vscode/vex_project_settings.json`文件,修改`project`的`name`属性,修改烧录端口请使用插件的按键
  2. 模板给出基本代码框架,请根据每个文件的提示完成修改任务,主要修改`src`目录下的`main.cpp`、`pidControl.cpp`、`robot-config.cpp`,`include`目录下的`robot-config.h`文件和`tjulib-chassis/ordinary-chassis/ordistraight.hpp`文件,鼓励自己研究并编写定位系统
  3. 如果你需要自己实现一些其他方法,请在include文件夹中定义(参考地盘类实现方式),并记得在`tjulib.h`头文件中声明

## 🤝 团队协作指南

### 1. 初次克隆项目
```bash
git clone https://github.com/A1C1NY/VEX-Freshmen-Group-1.git
cd VEX-Freshmen-Group-1
```

### 2. 创建功能分支
```bash
# 确保在main分支上
git checkout main
git pull origin main

# 创建新的功能分支
git checkout -b feature/your-feature-name
# 或者创建修复分支
git checkout -b fix/your-bug-fix
```

### 3. 开发和提交
```bash
# 进行代码修改后
git add .
git commit -m "feat: 添加新功能描述"
# 或者
git commit -m "fix: 修复具体问题"
```

### 4. 推送分支
```bash
git push origin feature/your-feature-name
```

### 5. 创建Pull Request
1. 在GitHub网页上点击 "Compare & pull request"
2. 填写PR标题和描述
3. 请求团队成员审查
4. 等待审查和合并

### 6. 同步最新代码
```bash
# 定期同步main分支的最新代码
git checkout main
git pull origin main

# 将最新代码合并到你的功能分支
git checkout feature/your-feature-name
git merge main
```

### 7. 分支命名规范
- `feature/功能名称` - 新功能开发
- `fix/问题描述` - Bug修复
- `docs/文档说明` - 文档更新
- `refactor/重构说明` - 代码重构

### 8. 提交信息规范
- `feat: 新功能`
- `fix: 修复bug`
- `docs: 文档更新`
- `style: 代码格式`
- `refactor: 重构`
- `test: 测试相关`

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
