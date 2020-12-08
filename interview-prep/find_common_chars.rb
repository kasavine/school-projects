=begin
    array A of strings
    only lowercase letters
    return a list of all characters
    that show up in all strings within the list
    dupliccates included

    ["bella", "label", "roller"] --> ['e', 'l', 'l']
    ["cook", "lock", "clock"] --> ["c", "o", "k"]
=end

def generate_characters_count_map(word)
    characters_count = Hash.new
    word_len = word.length
    0.upto word_len-1 do |i|
        current_count = characters_count[word[i]]
        if current_count == nil
            current_count = 0
        end
        current_count += 1
        characters_count[word[i]] = current_count
    end
    characters_count
end

def count(words)
    characters_count = Array.new()
    0.upto words.length - 1 do |i|
        characters_count.push generate_characters_count_map(words[i])
    end

    first_characters_count = characters_count[0]
    result = Hash.new
    0.upto first_characters_count.keys.length - 1 do |i|
        char = first_characters_count.keys[i]
        min = first_characters_count[char]
        0.upto characters_count.length - 1 do |i2|
            if characters_count[i2][char] == nil
                min = nil
                break
            end
            if characters_count[i2][char] < min
                min = characters_count[i2][char]
            end
        end
        if min != nil
            result[char] = min
        end
    end
                
    return result
end

p count(["cook", "lock", "clock"])
p generate_characters_count_map("bella")