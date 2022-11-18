# coding=utf-8
"""
二分查找
"""
def binary_search(lst, item):
    low = 0     # low和high用于跟踪要在其中查找的列表部分
    high = len(lst) - 1

    while(low <= high):     # 只要范围没有缩小到只包含一个元素
        mid = (low + high) // 2  # 就检查中间的元素
        guess = lst[mid]
        if guess == item:   # 找到了元素
            return mid
        if guess > item:    # 猜的数字大了
            high = mid - 1
        else:               # 猜的数字小了
            low = mid + 1
    return None            # 没有指定的元素


if __name__ == '__main__':
    my_list = [1, 3, 5, 7, 9]
    print(binary_search(my_list, 3))
    print(binary_search(my_list, -1))
