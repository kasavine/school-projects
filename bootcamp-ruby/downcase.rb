def downcase(string)
    index = 0
    while string[index]
        if (string[index] >= ("A".ord).chr and string[index] <= ("Z".ord).chr)
            string[index] = (string[index].ord + 32).chr
        else
            string[index] = (string[index].ord).chr
        end
        index += 1
    end
    return string
end