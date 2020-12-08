require 'date'

def parse_domain(mail)
    return mail.split("@")[1]
end

def parse_age(age_str)
    age = age_str.to_i
    if age <= 20
        return "1->20"
    elsif age <= 40
        return "21->40" 
    elsif age <= 65
        return "41->65"
    elsif age <= 99
        return "66->99"
    end
    return -1
end

def parse_time(date_time_str)
    date_time = DateTime.parse(date_time_str, "%Y-%m-%d %H:%M:%S")
    if date_time.hour < 12
        return "morning"
    elsif date_time.hour < 18
        return "afternoon"
    elsif date_time.hour < 24
        return "evening"
    end
    return -1
end

def my_updated_csv_parser(csv_content, separator)
    splited_by_separator = csv_content.split(separator)
    len = splited_by_separator.length
    1.upto (len - 1) do |index|
        line = splited_by_separator[index]
        fields = line.split(",")
        fields[4] = parse_domain(fields[4])
        fields[5] = parse_age(fields[5])
        fields[9] = parse_time(fields[9])
        splited_by_separator[index] = fields.join(",")
    end
    return splited_by_separator
end

def data_transform(csv_content)
    res = my_updated_csv_parser(csv_content, "\n")
    return res
end

p data_transform("Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At\nMale,Carl,Wilderman,carl,wilderman_carl@yahoo.com,29,Seattle,Safari iPhone,2,2020-03-06 16:37:56\nMale,Marvin,Lind,marvin,marvin_lind@hotmail.com,77,Detroit,Chrome Android,2,2020-03-02 13:55:51\nFemale,Shanelle,Marquardt,shanelle,marquardt.shanelle@hotmail.com,21,Las Vegas,Chrome,1,2020-03-05 17:53:05\nFemale,Lavonne,Romaguera,lavonne,romaguera.lavonne@yahoo.com,81,Seattle,Chrome,2,2020-03-04 10:33:53\nMale,Derick,McLaughlin,derick,mclaughlin.derick@hotmail.com,47,Chicago,Chrome Android,1,2020-03-05 15:19:48\n")
