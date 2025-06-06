/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/6/5.
//

#pragma once

#include "common/sys/rc.h"
#include "sql/expr/expression.h"
#include "sql/stmt/stmt.h"

class Db;
class Table;

/**
 * @brief 描述算术运算语句
 * @ingroup Statement
 */
class CalcStmt : public Stmt
{
public:
  CalcStmt()                   = default;
  virtual ~CalcStmt() override = default;

  StmtType type() const override { return StmtType::CALC; }

public:
  static RC create(CalcSqlNode &calc_sql, Stmt *&stmt)
  {
    CalcStmt *calc_stmt     = new CalcStmt();
    calc_stmt->expressions_ = std::move(calc_sql.expressions);
    stmt                    = calc_stmt;
    return RC::SUCCESS;
  }

public:
  vector<unique_ptr<Expression>> &expressions() { return expressions_; }

private:
  vector<unique_ptr<Expression>> expressions_;
};
