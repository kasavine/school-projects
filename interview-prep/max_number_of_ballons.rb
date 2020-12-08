=begin
    given a string text, you want to use the chars of text 
    to form as many instances of the world "balloon" as possible
    use each char in the text at most once
    return the maximun number of instances that can be performed
    text -- 1 <= text length <= 10, lowercase, english alphabet
    
    "nlaebolka" - 1
    "loonbalxballpoon" - 2
=end

def hash_of_letters(string)
    result = Hash.new
    0.upto string.length - 1 do |index|
        current = result[string[index]]
        if current == nil
            current = 0
        end
        current += 1
        result[string[index]] = current
    end
    return result
    # result.each {|key, value| puts "#{key} is #{value}" }
end

def how_many_balloons(string)
    letters = hash_of_letters(string)
    if letters["l"] == nil or letters["o"] == nil
        return 0
    end
    letters["l"] = letters["l"].to_i / 2
    letters["o"] = letters["o"].to_i / 2

    target = "balon"
    min_number = letters[target[0]]
    0.upto target.length - 1 do |i|
        char = target[i]
        current_number = letters[char]
        if current_number == nil
            return 0
        end
        if current_number < min_number
            min_number = current_number
        end
    end
    return min_number
end

p how_many_balloons("string")
p how_many_balloons("stringwithoneballoon")
p how_many_balloons("stringwithtwoballoonsballoons")
p how_many_balloons("string withthreeballooonsballoonssbaloooooln")
p how_many_balloons("stringwithfourballoonsballoonsballoonsnnnnssbaloonsl")

