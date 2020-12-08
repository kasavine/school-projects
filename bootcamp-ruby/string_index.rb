def string_index(haystack, needle)
    index = 0
    len = haystack.length

    while index < len
        if haystack[index] === needle
            return index
            break
        end
        index += 1
    end
    return -1
end

# puts string_index("hello", "l")
# puts string_index("hello", "p")
# puts string_index("hello", "o")
# puts string_index("hello", "e")