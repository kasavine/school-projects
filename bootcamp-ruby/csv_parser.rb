##
## QWASAR.IO -- my_csv_parser
##
## @param {String} param_1
## @param {String} param_2
##
## @return {string[][]}
##
##  "a,b,c,e\n1,2,3,4\n" && ","
##  [["a", "b", "c", "e"], ["1", "2", "3", "4"]]

def csv_parser(csv_content, separator)
    array_split = Array.new(csv_content.split("\n")){Array.new}
    len = array_split.length
    0.upto (len - 1) do |index|
        array_split[index] = Array.new(array_split[index].split(separator))
    end
    return array_split
end

p csv_parser( "a,b,c,e\n1,2,3,4\n", ",")
p csv_parser( "a,b,c,e\n1,2,3,4\nc,d,f,j\n", ",")