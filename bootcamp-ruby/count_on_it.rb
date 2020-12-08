def count_on_it(array_of_strings)
    len = array_of_strings.length
    index = 0
    array_of_ints = Array.new
    while len > index
         array_of_ints[index] = array_of_strings[index].length
         index += 1
    end
    return array_of_ints
end

# p count_on_it(["This", "is", "the", "way"])