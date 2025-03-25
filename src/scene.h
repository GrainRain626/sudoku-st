#ifndef _SUDOKU_SCENE_H_
#define _SUDOKU_SCENE_H_

#include <iostream>
#include <vector>

#include "common.h"
#include "block.h"
#include "command.h"

// 数独场景类
class CScene
{
public:
    CScene(int index = 3);
    virtual ~CScene();

    void generate();   // 生成数独场景
    void show() const; // 打印场景

    bool setCurValue(const int nCurValue, int &nLastValue);
    bool setPointValue(const point_t &, const int);
    point_t getCurPoint();

    void eraseRandomGrids(const int count); // 随机擦除某数量的数独格子
    bool isComplete();                      // 判断是否完成数独

    void play();                            // 开始游戏
    bool save(const char *filename);        // 保存游戏数据至filename文件
    bool load(const char *filename);        // 从filename文件读取游戏进度

    void setMode(KeyMode mode);             // 设置键盘模式: Normal / Vim

private:
    void init();                                 // 将每个格子的指针放到block里面
    void setValue(const int);
    void setValue(const point_t &, const int);
    void printUnderline(int line_no = -1) const;

private:
    KeyMap *keyMap{};
    int _max_column;
    point_t _cur_point;
    CBlock _column_block[9]; // 存每列的9个数字
    CBlock _row_block[9];    // 存每行的9个数字
    CBlock _xy_block[3][3];  // 存每个3*3区域的数字
    point_value_t _map[81];  // 存整个数独地图

    std::vector<CCommand> _vCommand;
};

#endif