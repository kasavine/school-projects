## Calculate the Hamming difference between two DNA strands.

def hamming_dna(string1, string2)
    len_s1 = string1.length
    len_s2 = string2.length

    if len_s1 != len_s2
        return -1
    else
        count = 0
        0.upto (len_s1 - 1) do |index|
            next if (string1[index] === string2[index])
            if (string1[index] != string2[index])
                count += 1
            end
        end
        return count
    end
    return count
end


# def test
#     string1 = "GAGCCTACTAACGGGAT"
#     string2 = "CATCGTAATGACGGCCT"
#             ## ^ ^ ^  ^ ^    ^^
#     string3 = "GAGCCTACTAACGGGAT00"
    
#     ## s1 == s2
#     p hamming_dna(string1, string2)
#     ## s1 < s2
#     p hamming_dna(string1, string3)
#     ## s2 > s1
#     p hamming_dna(string3, string2)
# end

# test()