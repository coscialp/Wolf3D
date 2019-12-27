# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    generator.rb                                     .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/27 19:09:46 by coscialp     #+#   ##    ##    #+#        #
#    Updated: 2019/12/27 19:31:57 by coscialp    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

def		map_name
	if ARGV.first
		name = ARGV.first
	else
		puts "Map's name ?"
		printf "> "
		name = gets.chomp
	end
	return name
end

def		get_resoltion_x
	puts "resolution x ?"
	printf "> "
	x = gets.chomp
	return x
end

def		get_resoltion_y
	puts "resolution y ?"
	printf "> "
	y = gets.chomp
	return y
end

def		get_path_texture
	puts "Textures directory's path ?"
	print "> "
	path = gets.chomp
	return path
end

def		get_texture_name(path, orientation)
	puts "#{orientation} texture's name ?"
	print "> "
	texture_name = gets.chomp
	texture_name = orientation.join(texture_name)
	return texture_name
end

def		create_map(name)
	file = File.new(name, w+)
	return file
end

