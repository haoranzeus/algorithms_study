# coding=utf-8
"""
选择排序
"""
def find_smallest(arr):
    smallest = arr[0]       # 存储最小值
    smallest_index = 0      # 存储最小元素的索引
    for i in range(1, len(arr)):
        if arr[i] < smallest:
            smallest = arr[i]
            smallest_index = i
    return smallest_index


def select_sort(arr):
    new_arr = []
    for i in range(len(arr)):
        smallest = find_smallest(arr)   # 找到最小元素，将其加入新数组
        new_arr.append(arr.pop(smallest))
    return new_arr


if __name__ == '__main__':
    print(select_sort([5, 3, 6, 2, 10]))
