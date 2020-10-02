/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shader_program.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:49:00 by lmittie           #+#    #+#             */
/*   Updated: 2020/01/25 15:32:28 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <fcntl.h>
#include <unistd.h>

char		*read_file(const char *file)
{
	int		fd;
	char	buff[4097];
	char	*line;
	int		bytes;

	fd = open(file, O_RDONLY);
	line = NULL;
	if (fd < 0 || read(fd, buff, 0) < 0)
		exit(-1);
	while ((bytes = read(fd, buff, 4096)) != 0)
	{
		buff[bytes] = '\0';
		line = ft_strjoin_free(line, buff, 1, 0);
	}
	return (line);
}

void		check_logs(GLuint shader)
{
	GLint	is_linked;
	GLint	length;
	char	*log;

	glGetProgramiv(shader, GL_LINK_STATUS, &is_linked);
	if (is_linked == GL_FALSE)
	{
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		log = malloc(length);
		glGetShaderInfoLog(shader, length, &length, log);
		ft_putendl("Error linking shader compilation:");
		ft_putendl(log);
		free(log);
		exit(-1);
	}
}

void		is_compiled(GLuint shader, GLenum type)
{
	GLint	success;
	GLint	length;
	char	*log;

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (success == GL_TRUE)
		return ;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
	log = malloc(length);
	glGetShaderInfoLog(shader, length, &length, log);
	if (type == GL_FRAGMENT_SHADER)
	{
		ft_putendl("Error fragment shader compilation:");
		ft_putendl(log);
	}
	else if (type == GL_VERTEX_SHADER)
	{
		ft_putendl("Error vertex shader compilation:");
		ft_putendl(log);
	}
	free(log);
	exit(-1);
}

t_shader	create_shader_program(const char *vertex_shader,
									const char *fragment_shader)
{
	t_shader		shader;
	const char		*shader_source;
	GLint			size;

	shader_source = read_file(vertex_shader);
	size = ft_strlen(shader_source);
	shader.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader.vertex_shader, 1, &shader_source, &size);
	glCompileShader(shader.vertex_shader);
	is_compiled(shader.vertex_shader, GL_VERTEX_SHADER);
	shader_source = read_file(fragment_shader);
	size = ft_strlen(shader_source);
	shader.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader.fragment_shader, 1, &shader_source, &size);
	glCompileShader(shader.fragment_shader);
	is_compiled(shader.fragment_shader, GL_FRAGMENT_SHADER);
	shader.shader_program = glCreateProgram();
	glAttachShader(shader.shader_program, shader.vertex_shader);
	glAttachShader(shader.shader_program, shader.fragment_shader);
	glLinkProgram(shader.shader_program);
	check_logs(shader.shader_program);
	return (shader);
}
