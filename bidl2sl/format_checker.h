/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

/**
 * @file     format_checker.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月16日 15时47分48秒
 *  
 **/
#ifndef _BIDL2SL_FORMAT_CHECKER_H_
#define _BIDL2SL_FORMAT_CHECKER_H_

#include <string>

class FormatChecker {
public:
    /**
     * @brief is_bidl_filename_valid 检查bidl文件是否以'.bidl'结尾
     *
     * @param bidl
     *
     * @return 
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年08月16日 15时49分23秒
     */
    static bool is_bidl_filename_valid(const std::string& bidl);
};
#endif // _BIDL2SL_FORMAT_CHECKER_H_

