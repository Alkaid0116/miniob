/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#pragma once

#include "sql/optimizer/cascade/tasks/cascade_task.h"
#include "sql/optimizer/cascade/group.h"

/**
 * @brief: OptimizeGroup, find the best plan for a group
 */
class OptimizeGroup : public CascadeTask
{
public:
  OptimizeGroup(Group *group, OptimizerContext *context)
      : CascadeTask(context, CascadeTaskType::OPTIMIZE_GROUP), group_(group)
  {}

  void perform() override;

private:
  Group *group_;
};