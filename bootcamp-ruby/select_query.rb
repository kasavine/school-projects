class MySelectQuery

	def initialize(csv_content)
		@data = csv_parser(csv_content, ",")
	end

	def where(column_name, criteria)
		answer = Array.new
        len = @data[0].length
        col_index = -1
        0.upto (len - 1) do |index|
            if @data[0][index] === column_name 
                col_index = index
            end
        end
        if col_index != -1
            d_len = @data.length
            i = 0
            1.upto (d_len - 1) do |index|
                if @data[index][col_index] === criteria 
                    answer[i] = @data[index]*','
                    i += 1
                end
            end 
        end
		return answer
	end

	def csv_parser(csv_content, separator)
		array_split = Array.new(csv_content.split("\n")){Array.new}
		len = array_split.length
		0.upto (len - 1) do |index|
			array_split[index] = Array.new(array_split[index].split(separator))
		end
		return array_split
	end
end

## "name,year_start,year_end,position,height,weight,birth_date,college\n
## Alaa Abdelnaby,1991,1995,F-C,6-10,240,'June 24, 1968',Duke University\n
## Zaid Abdul-Aziz,1969,1978,C-F,6-9,235,'April 7, 1946',Iowa State University\n
## Kareem Abdul-Jabbar,1970,1989,C,7-2,225,'April 16, 1947','University of California, Los Angeles\n
## Mahmoud Abdul-Rauf,1991,2001,G,6-1,162,'March 9, 1969',Louisiana State University\n"

my_queue = MySelectQuery.new("name,year_start,year_end,position,height,weight,birth_date,college\nAndre Brown,1991,1995,F-C,6-10,240,'June 24, 1968',Duke University\nZaid Abdul-Aziz,1969,1978,C-F,6-9,235,'April 7, 1946',Iowa State University\nKareem Abdul-Jabbar,1970,1989,C,7-2,225,'April 16, 1947','University of California, Los Angeles
Mahmoud Abdul-Rauf,1991,2001,G,6-1,162,'March 9, 1969',Louisiana State University\n")

p my_queue.where("year_start", "1991")