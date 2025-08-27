#include "h.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
// 学生类（Qo000）：封装学生信息与成绩
QoK012 Qo000 {
QoK013:
    std::string Qo0;     // 学号
    std::string Qo01;    // 姓名
    QoK003 Qo02;         // 数学成绩
    QoK003 Qo03;         // 语文成绩
    QoK003 Qo04;         // 英语成绩
QoK014:
    // 构造函数：初始化学生信息
    Qo000(std::string Qo100, std::string Qo101, QoK003 Qo102, QoK003 Qo103, QoK003 Qo104)
        : Qo0(Qo100), Qo01(Qo101), Qo02(Qo102), Qo03(Qo103), Qo04(Qo104) {}
    // 获取平均分
    QoK003 Qo05() QoK004 {
        QoK005 (Qo02 + Qo03 + Qo04) / 3.0;
    }
    // 信息获取接口（避免直接访问私有成员）
    std::string Qo06() QoK004 { QoK005 Qo0; }   // 获取学号
    std::string Qo07() QoK004 { QoK005 Qo01; }  // 获取姓名
    QoK003 Qo08() QoK004 { QoK005 Qo02; }       // 获取数学成绩
    QoK003 Qo09() QoK004 { QoK005 Qo03; }       // 获取语文成绩
    QoK003 Qo010() QoK004 { QoK005 Qo04; }      // 获取英语成绩
    // 成绩修改接口
    QoK001 Qo011(QoK003 Qo105) { Qo02 = Qo105; } // 修改数学成绩
    QoK001 Qo012(QoK003 Qo106) { Qo03 = Qo106; } // 修改语文成绩
    QoK001 Qo013(QoK003 Qo107) { Qo04 = Qo107; } // 修改英语成绩
};
// 成绩管理系统类（Qo014）：管理学生列表与业务逻辑
QoK012 Qo014 {
QoK013:
    std::vector<Qo000> Qo015;  // 存储学生信息的容器
QoK014:
    // 1. 添加学生
    QoK001 Qo016(const Qo000& Qo108) {
        Qo015.push_back(Qo108);
    }
    // 2. 显示所有学生信息
    QoK001 Qo017() QoK004 {
        QoK006 (Qo015.empty()) {
            std::cout << "没有学生信息可显示！" << std::endl;
            QoK005;
        }
        // 打印表头
        std::cout << std::left << std::setw(15) << "学号" 
                  << std::setw(10) << "姓名" 
                  << std::setw(10) << "数学" 
                  << std::setw(10) << "语文" 
                  << std::setw(10) << "英语" 
                  << std::setw(10) << "平均分" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        // 遍历学生列表
        QoK008 (QoK000 Qo109 = 0; Qo109 < Qo015.size(); ++Qo109) {
            const auto& Qo110 = Qo015[Qo109];
            std::cout << std::left << std::setw(15) << Qo110.Qo06()
                      << std::setw(10) << Qo110.Qo07()
                      << std::setw(10) << Qo110.Qo08()
                      << std::setw(10) << Qo110.Qo09()
                      << std::setw(10) << Qo110.Qo010()
                      << std::setw(10) << std::fixed << std::setprecision(2) << Qo110.Qo05() << std::endl;
        }1
    // 3. 按学号查找学生
    QoK002 Qo018(const std::string& Qo111) QoK004 {
        QoK008 (QoK000 Qo112 = 0; Qo112 < Qo015.size(); ++Qo112) {
            const auto& Qo113 = Qo015[Qo112];
            QoK006 (Qo113.Qo06() == Qo111) {
                std::cout << "找到学生信息：" << std::endl;
                std::cout << std::left << std::setw(15) << "学号" 
                          << std::setw(10) << "姓名" 
                          << std::setw(10) << "数学" 
                          << std::setw(10) << "语文" 
                          << std::setw(10) << "英语" 
                          << std::setw(10) << "平均分" << std::endl;
                std::cout << "-------------------------------------------------------------" << std::endl;
                std::cout << std::left << std::setw(15) << Qo113.Qo06()
                          << std::setw(10) << Qo113.Qo07()
                          << std::setw(10) << Qo113.Qo08()
                          << std::setw(10) << Qo113.Qo09()
                          << std::setw(10) << Qo113.Qo010()
                          << std::setw(10) << std::fixed << std::setprecision(2) << Qo113.Qo05() << std::endl;
                QoK005 QoK018; // 找到返回true
            }
        }
        std::cout << "未找到学号为 " << Qo111 << " 的学生！" << std::endl;
        QoK005 QoK019; // 未找到返回false
    }
    // 4. 查找平均分最高的学生
    QoK001 Qo019() QoK004 {
        QoK006 (Qo015.empty()) {
            std::cout << "没有学生信息可统计！" << std::endl;
            QoK005;
        }
        QoK003 Qo114 = -1.0; // 最高平均分（初始值设为负数，避免与0分冲突）
        const Qo000* Qo115 = QoK020; // 指向最高分学生的指针
        // 遍历找最高分
        QoK008 (QoK000 Qo116 = 0; Qo116 < Qo015.size(); ++Qo116) {
            const auto& Qo117 = Qo015[Qo116];
            QoK006 (Qo117.Qo05() > Qo114) {
                Qo114 = Qo117.Qo05();
                Qo115 = &Qo117;
            }
        }
        // 打印结果
        std::cout << "平均分最高的学生是：" << std::endl;
        std::cout << std::left << std::setw(15) << "学号" 
                  << std::setw(10) << "姓名" 
                  << std::setw(10) << "平均分" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << std::left << std::setw(15) << Qo115->Qo06()
                  << std::setw(10) << Qo115->Qo07()
                  << std::setw(10) << std::fixed << std::setprecision(2) << Qo115->Qo05() << std::endl;
    }
    // 5. 按平均分从高到低排序
    QoK001 Qo020() {
        std::sort(Qo015.begin(), Qo015.end(),
                  [](const Qo000& Qo118, const Qo000& Qo119) {
                      QoK005 Qo118.Qo05() > Qo119.Qo05(); // 降序排序
                  });
        std::cout << "已按平均分从高到低排序！" << std::endl;
    }

    // 6. 获取当前学生总数
    QoK000 Qo021() QoK004 {
        QoK005 Qo015.size();
    }
};

// 显示菜单（独立函数Qo022）
QoK001 Qo022() {
    std::cout << "\n===== 学生成绩管理系统 =====" << std::endl;
    std::cout << "1. 添加学生信息" << std::endl;
    std::cout << "2. 显示所有学生信息" << std::endl;
    std::cout << "3. 按学号查找学生" << std::endl;
    std::cout << "4. 查找平均分最高的学生" << std::endl;
    std::cout << "5. 按平均分排序" << std::endl;
    std::cout << "6. 退出系统" << std::endl;
    std::cout << "请选择操作(1-6)：";
}

// 主函数：程序入口
QoK000 main() {
    Qo014 Qo120;  // 创建成绩管理系统对象
    QoK000 Qo121; // 存储用户菜单选择

    // 主循环：持续接收用户操作
    QoK010 {
        Qo022(); // 显示菜单
        std::cin >> Qo121;

        // 菜单逻辑分支
        QoK015 (Qo121) {
            QoK016 1: { // 1. 添加学生
                std::string Qo122, Qo123; // 学号、姓名
                QoK003 Qo124, Qo125, Qo126; // 数学、语文、英语成绩

                std::cout << "请输入学号：";
                std::cin >> Qo122;
                std::cout << "请输入姓名：";
                std::cin >> Qo123;
                std::cout << "请输入数学成绩：";
                std::cin >> Qo124;
                std::cout << "请输入语文成绩：";
                std::cin >> Qo125;
                std::cout << "请输入英语成绩：";
                std::cin >> Qo126;

                Qo000 Qo127(Qo122, Qo123, Qo124, Qo125, Qo126);
                Qo120.Qo016(Qo127);
                std::cout << "学生信息添加成功！当前学生总数：" << Qo120.Qo021() << std::endl;
                QoK011;
            }

            QoK016 2: // 2. 显示所有学生
                Qo120.Qo017();
                QoK011;

            QoK016 3: { // 3. 按学号查找
                std::string Qo128;
                std::cout << "请输入要查找的学号：";
                std::cin >> Qo128;
                Qo120.Qo018(Qo128);
                QoK011;
            }

            QoK016 4: // 4. 查找最高分学生
                Qo120.Qo019();
                QoK011;

            QoK016 5: // 5. 排序
                Qo120.Qo020();
                QoK011;

            QoK016 6: // 6. 退出
                std::cout << "感谢使用，再见！" << std::endl;
                QoK011;

            QoK017: // 无效选择
                std::cout << "无效的选择，请重新输入（1-6）！" << std::endl;
        }
    } QoK009 (Qo121 != 6); // 选择6时退出循环

    QoK005 0;
}