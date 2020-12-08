def map_mult_two(array_of_ints)
    index = 0
    mult = 2
    while index < array_of_ints.length
        array_of_ints[index] = mult * array_of_ints[index]
        index += 1
    end
    return array_of_ints
end