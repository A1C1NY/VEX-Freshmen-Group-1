// 此文件实现了一个直线运动的底盘类，继承自Ordi_BaseChassis类，并实现了直线移动和转向功能。
// 你应当修改以下部分:
// 1.根据自学知识补全moveInches方法,学习控制器的编写方法
// 2.模仿moveInches方法,编写turnToAngle方法,
//   你的turnToAngle应当是转向指定角度,在编写控制器时,你的反馈量可以从imu中获取

#pragma once
#include "tjulib-chassis/ordinary-chassis/ordi-base.hpp"
#include "tjulib-position/Position.hpp"

extern double zero_drift_error;


namespace tjulib
{
    using namespace vex;

    class Ordi_StraChassis : virtual public Ordi_BaseChassis
    {
    protected:
        Position *position = NULL;
        pidControl *fwdControl = NULL;  // 直线移动pid控制器
        pidControl *turnControl = NULL; // 转向pid控制器
    private:
        const double PI = 3.14159265358979323846;

    protected:
    public:
        Ordi_StraChassis(std::vector<std::vector<vex::motor *> *> &_chassisMotors,pidControl *_fwdpid, pidControl *_turnpid)
            : Ordi_BaseChassis(_chassisMotors, _fwdpid, _turnpid),
              fwdControl(_fwdpid), turnControl(_turnpid) {}

        // 把角度转换到360度以内
        double getWrap360(double currentAngle)
        {
            while(currentAngle >= 360)
                currentAngle -= 360;
            while(currentAngle < 0)
                currentAngle += 360;
            return currentAngle;
        }
        // 底盘刹车
        void setStop(vex::brakeType brakeType)
        {
            for (vex::motor *motor : (_leftMotors))
            {
                motor->setBrake(brakeType);
            }
            for (vex::motor *motor : (_rightMotors))
            {
                motor->setBrake(brakeType);
            }
        }
        
        void turnToAngle(double angle, T maxSpeed, double maxtime_ms = 5000, int fwd = 1)
        {
            // 仿照moveInches函数的写法，自行实现该函数
            // 目标：输入指定的航向，让机器人能够转到指定的航向(20250628完成)
            // Angle 下的计时器
            timer mytime;
            mytime.clear();

            // 变量和初始参数
            T finalTurnSpeed = 0;
            T targetAngle = getWrap360(angle);
            T angleError = 0;
            turnControl->resetpid();

            while (!turnControl->overflag()){
                // 计算当前角度
                T currAngle = getWrap360(imu.heading(degrees));
                
                // 计算角度与目标还有多少
                angleError = targetAngle - currAngle;

                // 使其走最短路径
                if (angleError > 180){
                    angleError -= 360;
                } else if (angleError < -180){
                    angleError += 360;
                }

                // 如果误差已经在范围内，就增加cnt数
                if (fabs(angleError) <= turnControl->params->errorThreshold){
                    turnControl->cnt++;
                }
                // 如果超过了给定的maxtime，则退出循环
                if (mytime.time(msec) >= maxtime_ms)
                {
                    break;
                }
                finalTurnSpeed = turnControl->pidCalcu(angleError, maxSpeed, 0);

                // 控制最小速度以克服阻力
                if (fabs(finalTurnSpeed) < turnControl->params->minSpeed){
                    if (finalTurnSpeed > 0){
                        finalTurnSpeed = turnControl->params->minSpeed;
                    }
                    else if (finalTurnSpeed < 0){
                        finalTurnSpeed = -turnControl->params->minSpeed;
                    }
                }
                
                // 这里规定右转(顺时针为正)，所以左轮是负值右轮是正值
                VRUN(-finalTurnSpeed, finalTurnSpeed);
                task::sleep(25);
            }
            VRUN(0, 0);
            setStop(vex::brakeType::brake);
            turnControl->resetpid();
        }

        // 直线移动函数,通过pid控制器让机器人向前走指定的距离(20250628完成)
        void moveInches(T inches, T maxSpeed, double maxtime_ms = 5000, int fwd = 1)
        {
            // 定义计时器
            timer mytime;
            mytime.clear();

            // 定义变量和初始化参数
            // 这里所有Distant都是调用的前面的运转总里程
            T finalFwdSpeed = 0;
            T targetDistant = inches;
            T startError = (position->LeftBaseDistance + position->RightBaseDistance) / 2;
            fwdControl->resetpid();
            
            // 循环判断条件：是否到达指定容差内指定时间以上（这里用循环次数代表时间）
            // 自行填写（用pidControl类里面的函数）(20250628完成)
            while (!fwdControl -> overflag()) 
            {
                // 计算当前误差（还需要往前走多少）
                // 自行填写(20250628完成)
                T currDistant = (position->LeftBaseDistance + position->RightBaseDistance) / 2; // 更新获取现在位置
                targetDistant = inches - (currDistant - startError);
                // 如果当前误差已在容差范围内，则增加cnt计数
                // 自行填写（用pidPara里面的参数进行判断）(20250628完成)
                if (fabs(targetDistant) <= fwdControl->params->errorThreshold)
                {
                    fwdControl->cnt++;
                }
                // 如果超过了给定的maxtime，则退出循环
                if (mytime.time(msec) >= maxtime_ms)
                {
                    break;
                }
                // 用pid控制器计算速度
                // 自行填写(20250628完成)
                finalFwdSpeed = fwdControl->pidCalcu(targetDistant, maxSpeed, 0);

                // 控制最小速度，让车辆底盘的电压至少能够克服阻力
                if (fabs(finalFwdSpeed)<fwdControl->params->minSpeed) 
                    {
                        if(finalFwdSpeed >= 0)
                        {
                            finalFwdSpeed = fwdControl->params->minSpeed;
                        }
                        else
                        {
                            finalFwdSpeed = - fwdControl->params->minSpeed;
                        }
                    }
                
                // 如果是向后走，则速度取反
                if (!fwd)
                    finalFwdSpeed = -finalFwdSpeed;
                
                // 把计算得到的速度输出
                VRUN(finalFwdSpeed, finalFwdSpeed);
                task::sleep(25);
            }
            // 完成循环以后把车停下
            VRUN(0, 0);
            setStop(vex::brakeType::brake);
            fwdControl->resetpid();
        }

    };
}