=begin
 
given an array of integers
find if the array contains duplicates
true - if any value appears at least twice in the array
flase - if every element is distict

    [1, 2, 3, 1] - true
    [1, 2, 3, 4] - false
    [1, 1, 1, 2, 2, 3, 3, 4, 4] - true
=end

def count_elements_in_array(array)

    result = Hash.new(0)
    array.each do |num|
        current_count = result[num]
        current_count += 1
        result[num] = current_count
    end
    return result 
end


def  contains_duplicate(array)
    array_to_hash_counted = count_elements_in_array(array)

    array_to_hash_counted.each do |num, calcs|
        if array_to_hash_counted[num] > 1
            return true
        end
    end
    return false
end

p contains_duplicate([1, 5, -2, -4, 0])

p contains_duplicate([1, 53, 7, 7, 53])