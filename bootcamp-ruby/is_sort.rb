def is_sort(array_of_ints)
    len = array_of_ints.length
    index = 0
    while index < len - 2
        if ((array_of_ints[index] <= array_of_ints[index + 1]) and 
            (array_of_ints[index + 1] <= array_of_ints[index + 2])) or
            ((array_of_ints[index] >= array_of_ints[index + 1]) and
            (array_of_ints[index + 1] >= array_of_ints[index + 2]))
            index += 1
        else
            return false
        end
    end
    return true
end

# p is_sort([1, 1, 2])
# p is_sort([2, 1, -1])
# p is_sort([4, 7, 0])