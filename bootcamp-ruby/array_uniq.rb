def array_uniq(array_of_ints)
    unique_array_of_ints = Array.new
    i = 0
    while i < array_of_ints.length
        j = 0
        while j < unique_array_of_ints.length
            if array_of_ints[i] === unique_array_of_ints[j]
                break
            end
            j += 1
        end
        unique_array_of_ints[j] = array_of_ints[i]
        i += 1
    end
    return unique_array_of_ints
end

# print array_uniq([1, 1, 2, 2, 3, 4, 5, 0, 0, 4])