/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:09:55 by juandrie          #+#    #+#             */
/*   Updated: 2024/03/14 11:53:22 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>


void replaceAllOccurrences(std::string &str, const std::string &s1, const std::string &s2)
{
    if(s1.empty())
        return;

    size_t start_pos = 0;
    while((start_pos = str.find(s1, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, s1.length(), s2);
        start_pos += s2.length();
        if (s2.find(s1) != std::string::npos)
        {
            start_pos = str.find(s1, start_pos);
            if (start_pos == std::string::npos)
                break;
        }
    }
}

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::ifstream file_in(filename.c_str());
    if (!file_in.is_open())
    {
        std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
        return;
    }

    std::string outfile_name = filename + ".replace";
    std::ofstream file_out(outfile_name.c_str());
    if (!file_out.is_open())
    {
        std::cerr << "Could not create the file - '" << outfile_name << "'" << std::endl;
        return;
    }
    std::string line;
    while (getline(file_in, line))
    {
        replaceAllOccurrences(line, s1, s2);
        file_out << line << std::endl;
    }

    file_in.close();
    file_out.close();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string to replace> <string to replace with>" << std::endl;
        return 1;
    }
    const std::string filename(argv[1]);
    const std::string s1(argv[2]);
    const std::string s2(argv[3]);

    replaceInFile(filename, s1, s2);

    return (0);
}