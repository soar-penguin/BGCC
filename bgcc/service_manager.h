/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_SERVICE_MANAGER_H_
#define _BGCC2_SERVICE_MANAGER_H_

#include <map>
#include <string>
#include "shared_pointer.h"
#include "processor.h"
#include "mutex.h"

namespace bgcc {
    /**
     * @brief 管理一组服务实体。每个服务由单个processor来提供
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月21日 13时14分58秒
     */
    class ServiceManager {
    public:
        /**
         * @brief ServiceManager 构造函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月21日 16时22分29秒
         */
        ServiceManager();

        /**
         * @brief add_service 添加服务
         *
         * @param processor 服务实体
         *
         * @return 添加成功或服务已存在则返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月21日 13时15分51秒
         */
        int32_t add_service(SharedPointer<IProcessor> processor);

        /**
         * @brief remove_service 删除服务
         *
         * @param processor 服务实体
         *
         * @return 删除成功或服务不存在返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月21日 13时18分49秒
         */
        int32_t remove_service(SharedPointer<IProcessor> processor);

        /**
         * @brief remove_service 删除服务
         *
         * @param name 服务实体名称
         *
         * @return 删除成功或服务不存在返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月21日 13时21分49秒
         */
        int32_t remove_service(const std::string& name);

        /**
         * @brief remove_all_service 删除所有服务实体
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月21日 13时22分51秒
         */
        int32_t remove_all_service();

        /**
         * @brief get_service 获取服务实体
         *
         * @param name 服务实体名称
         *
         * @return 服务实体智能指针
         * @see
         * @note 在调用完成后，请调用返回值的is_valid()方法来检查返回值是否可用
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月21日 13时23分44秒
         */
        SharedPointer<IProcessor> get_service(const std::string& name) const;

        /**
         * @brief is_service_exist 检查特定服务实体是否存在
         *
         * @param name 服务实体名称
         *
         * @return true表示服务实体存在
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月21日 13时26分16秒
         */
        bool is_service_exist(const std::string& name) const;

        /**
         * @brief get_service_count 获取服务实体总数
         *
         * @return 服务实体总数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月21日 16时19分29秒
         */
        int32_t get_service_count() const;
    private:
        /**
         * @brief ServiceManager 禁用拷贝构造函数
         *
         * @param ServiceManager
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月21日 16时20分26秒
         */
        ServiceManager(const ServiceManager&);

        /**
         * @brief operator= 禁用赋值运算符
         *
         * @param ServiceManager
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月21日 16时20分41秒
         */
        ServiceManager& operator=(const ServiceManager&);

        typedef std::map<std::string, SharedPointer<IProcessor> > name2service_map;
        name2service_map _name2service;
        mutable Mutex _mutex;
    };
}
#endif // _BGCC2_SERVICE_MANAGER_H_

