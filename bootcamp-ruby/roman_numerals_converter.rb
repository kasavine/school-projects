## Write a function to convert from normal numbers to Roman Numerals.

## I, V, 	X, 		L, 		C, 		D, 		M
## 1, 5, 	10		50		100		500		1000
## 1990: 1000 + 900 + 90 + 0
## 		 M		CM	 XC		-> MCMXC

## 2008: 2000 + 5 + 3
## 		 MM + V + III -> MMVIII



def num_rom_converter(number)
	num = number
	result = String.new()
    # roman_nums = {
    # 1 => 'I',
    # 4 => 'IV',
    # 5 => 'V',
    # 9 => 'IX',
    # 10 => 'X',
    # 40 => 'XL',
    # 50 => 'L',
    # 90 => 'XC',
    # 100 => 'C',
	# 400 => 'CD',
	# 500 => 'D',
	# 900 => 'CM',
	# 1000 => 'M'
	# }
	# for num in [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    while num != 0
        if num >= 1000
            result += "M"
            num -= 1000
        elsif num >= 900
            result +=  "CM"
            num -= 900
        elsif num >= 500
            result +=  "D"
            num -= 500
        elsif num >= 400
            result +=  "CD"
            num -= 400
        elsif num >= 100
            result +=  "C"
            num -= 100
        elsif num >= 90
            result +=  "XC"
            num -= 90
        elsif num >= 50
            result +=  "L"
            num -= 50
        elsif num >= 40
            result +=  "XL"
            num -= 40
        elsif num >= 10
            result +=  "X"
            num -= 10
        elsif num >= 9
            result +=  "IX"
            num -= 9
        elsif num >= 5
            result +=  "V"
            num -= 5
        elsif num >= 4
            result +=  "IV"
            num -= 4
        elsif num >= 1
            result +=  "I"
            num -= 1
		end
	end 
	return result
end


# roman_Number = "";

#     while (number > 0)
#         if (number <= 4)
#             if ((1..3) === number)
#                 roman_Number += "I";
#                 number -= 1;
#             else
#                 roman_Number += "IV";
#                 number -= 4;
#             end
#         end

        # if ((5..9) === number)
        #     if ((5..8) === number)
        #         roman_Number += "V";
        #         number -= 5;
        #     else
        #         roman_Number += "IX";
        #         number -= 9;
        #     end
        # end

        # if ((10..49) === number)
        #     if ((10..39) === number)
        #         roman_Number += "X";
        #         number -= 10;
        #     else
        #         roman_Number += "XL";
        #         number -= 40;
        #     end
        # end

        # if ((50..99) === number)
        #     if ((50..89) === number)
        #         roman_Number += "L";
        #         number -= 50;
        #     else
        #         roman_Number += "XC";
        #         number -= 90;
        #     end
        # end

        # if ((100..499) === number)
        #     if ((100..399) === number)
        #         roman_Number += "C";
        #         number -= 100;
        #     else
        #         roman_Number += "CD";
        #         number -= 400;
        #     end
        # end

        # if ((500..999) === number)
        #     if ((500..899) === number)
        #         roman_Number += "D";
        #         number -= 500;
        #     else
        #         roman_Number += "CM";
        #         number -= 900;
        #     end
        # end

        # if (number >= 1000)
    #         roman_Number += "M";
    #         number -= 1000;
    #     end
    # end

    # return roman_Number;

p num_rom_converter(8)

p num_rom_converter(86)

p num_rom_converter(234)

p num_rom_converter(456)

p num_rom_converter(692)

p num_rom_converter(1345)

p num_rom_converter(1256)

p num_rom_converter(3900)
