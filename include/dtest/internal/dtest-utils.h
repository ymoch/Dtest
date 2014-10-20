//==============================================================================
/**
 * @file    dtest/internal/dtest-utils.h
 *
 * @brief   Dtest internal utilities
 *
 * @author  ymoch
 * @date    2014-10-19  ymoch
 */
//==============================================================================
#ifndef INCLUDE_DTEST_INTERNAL_DTEST_UTILS_H
#define INCLUDE_DTEST_INTERNAL_DTEST_UTILS_H

//==============================================================================
/**
 * @brief   uncopyable interface
 */
//==============================================================================
class Uncopyable
{
public:
    /**
     * @brief   constructor (allow default construcion)
     */
    Uncopyable() {}

    /**
     * @brief   destructor (allow destruction)
     */
    ~Uncopyable() {}

private:
    /**
     * @brief   copy constructor (forbid copy)
     */
    Uncopyable(const Uncopyable&);

    /**
     * @brief   assignment (forbid copy)
     */
    Uncopyable& operator=(const Uncopyable&);
};

#endif // INCLUDE_DTEST_INTERNAL_DTEST_UTILS_H
