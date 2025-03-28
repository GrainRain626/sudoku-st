#ifndef _SUDOKU_COMMAND_H_
#define _SUDOKU_COMMAND_H_

#include <memory>
#include "common.h"

// 前向申明嵌套的类
class CScene;

class CCommand
{
public:
    CCommand(CScene *pOwner);
    CCommand(CScene *pOwner, const point_t &point, int preValue, int curValue);
    CCommand(const CCommand &);
    ~CCommand();

    bool execute(int nInputValue);
    void undo();
    point_t getPoint() { return _stPoint; }
    int getPreValue() { return _nPreValue;}
    int getCurValue() { return _nCurValue; }
    void setPoint(const point_t &point) { _stPoint = point; }
    void setPreValue(const int preValue) { _nPreValue = preValue; }
    void setCurValue(const int curValue) { _nCurValue = curValue; }

private:
    CScene *_pOwner;
    point_t _stPoint;
    int _nPreValue;
    int _nCurValue;
};

#endif