
# col_names = {
#     0 => 'Gender',
#     1 => 'FirstName',
#     2 => 'LastName',
#     3 => 'UserName',
#     4 => 'Email',
#     5 => 'Age',
#     6 => 'City',
#     7 => 'Device',
#     8 => 'Coffee Quantity',
#     9 => 'Order At'
# }

# next if (i === 1 or i == 2 or i == 3 or i === 8)


require 'set'
require 'json'

def get_col_names(line)
    index = 0
    keys = line.split(",")
    col_names = Hash.new()
    while index < keys.length
        col_names[index] = keys[index]
        index += 1
    end
    return col_names
end

def add_line_to_data(my_hash, line, col_names)
    columns = line.split(",")
    skip_set = Set.new
        skip_set << 1
        skip_set << 2
        skip_set << 3
        skip_set << 8

    0.upto (col_names.length - 1) do |i|
        next if skip_set.include?(i)
        value = columns[i]
        col_name = col_names[i]
        if !my_hash.key?(col_name)
            my_hash[col_name] = Hash.new()
        end
        data = my_hash[col_name]
        if data.key?(value)
            data[value] += 1
        else
            data[value] = 1
        end
    end
end

def data_process(string)
    col_names = get_col_names(string[0])
    my_hash = Hash.new()
    index = 1
    while index < string.length
        add_line_to_data(my_hash, string[index], col_names)
        index += 1
    end
    return my_hash.to_json
end

puts data_process(["Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At", "Male,Carl,Wilderman,carl,yahoo.com,21->40,Seattle,Safari iPhone,2,afternoon", "Male,Marvin,Lind,marvin,hotmail.com,66->99,Detroit,Chrome Android,2,afternoon", "Female,Shanelle,Marquardt,shanelle,hotmail.com,21->40,Las Vegas,Chrome,1,afternoon", "Female,Lavonne,Romaguera,lavonne,yahoo.com,66->99,Seattle,Chrome,2,morning", "Male,Derick,McLaughlin,derick,hotmail.com,41->65,Chicago,Chrome Android,1,afternoon"])