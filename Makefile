# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 13:41:36 by nsilva-n          #+#    #+#              #
#    Updated: 2025/05/05 11:49:02 by nsilva-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC =	main.c	exit.c																										\
																															\
			builtin/ft_cd.c							builtin/ft_echo.c					builtin/ft_env.c					\
			builtin/ft_exit_builtin.c				builtin/ft_export.c					builtin/ft_pwd.c					\
			builtin/ft_unset.c																								\
																															\
			builtin_utils/ft_export_rec.c			builtin_utils/ft_isbuiltin.c		builtin_utils/ft_isflagn.c			\
			builtin_utils/ft_isnext.c				builtin_utils/ft_isvalidexport.c	builtin_utils/ft_update_pwd.c		\
																															\
			env/ft_env_to_strs.c					env/ft_error_env.c					env/ft_free_env.c					\
			env/ft_get_env.c						env/ft_init_mini_env.c													\
																															\
			exec/ft_access.c						exec/ft_error_execve.c				exec/ft_exec_builtin.c				\
			exec/ft_exec_single_cmd.c				exec/ft_execute.c					exec/ft_get_path.c					\
			exec/ft_isbadcommand.c					exec/ft_main_exec.c														\
																															\
			fd/ft_close_cmd_fds.c					fd/ft_close_fds.c					fd/ft_close.c						\
			fd/ft_error_redir.c						fd/ft_heredoc_expand.c				fd/ft_input_redir.c					\
			fd/ft_isfinaldoc.c						fd/ft_isloopdoc.c					fd/ft_last_heredoc.c				\
			fd/ft_open_app_out.c					fd/ft_open_doc.c					fd/ft_open_in_files_loop.c			\
			fd/ft_open_input_file.c					fd/ft_open_std_out.c				fd/ft_output_redir.c				\
			fd/ft_process_heredoc.c					fd/ft_rep_in_redir.c				fd/ft_rep_out_redir.c				\
			fd/ft_rl_to_doc.c						fd/ft_signal_exit.c														\
																															\
			global/ft_error.c						global/ft_free.c					global/ft_get_home.c				\
			global/ft_get_pid.c						global/ft_global.c					global/ft_init_global.c				\
																															\
			libft_utils/ft_atoll.c					libft_utils/ft_free_strs.c			libft_utils/ft_isdquote.c			\
			libft_utils/ft_islonglong.c				libft_utils/ft_isnumber.c			libft_utils/ft_isquote.c			\
			libft_utils/ft_isspace.c				libft_utils/ft_issquote.c			libft_utils/ft_strcmp.c				\
			libft_utils/ft_strjoin_gnl.c			libft_utils/ft_strs_count.c												\
																															\
			nodes/ft_count_node.c					nodes/ft_expand_node.c				nodes/ft_free_node.c				\
			nodes/ft_get_node_key.c					nodes/ft_get_node_value.c			nodes/ft_get_special_node.c			\
			nodes/ft_init_node.c					nodes/ft_isnode.c					nodes/ft_node_addback.c				\
			nodes/ft_node_key_len.c					nodes/ft_remove_node.c													\
																															\
			parse/ft_expand_nodes.c					parse/ft_expand_tilde.c				parse/ft_expand.c					\
			parse/ft_expanded_len.c					parse/ft_free_command.c				parse/ft_free_new_input.c			\
			parse/ft_hide_expand.c					parse/ft_init_index.c				parse/ft_isexpandneeded.c			\
			parse/ft_isspecialexpand.c				parse/ft_main_parse.c				parse/ft_tilde_loop.c				\
			parse/ft_unhide_expand.c																						\
																															\
			pipes/ft_child_process.c				pipes/ft_fill_pipes.c				pipes/ft_free_pipe_list.c			\
			pipes/ft_get_pipe_list.c				pipes/ft_init_pipe.c				pipes/ft_isvalidpipe.c				\
			pipes/ft_new_child.c					pipes/ft_pipe_addback.c				pipes/ft_pipe_count.c				\
																															\
			pipes_utils/ft_isvalidfirstparse.c		pipes_utils/ft_isvalidredir.c		pipes_utils/ft_waitpid.c			\
																															\
			quotes/ft_copy_woutquote.c				quotes/ft_isinquote.c				quotes/ft_quoted_len.c				\
			quotes/ft_remove_pipe_quotes.c			quotes/ft_remove_quotes.c			quotes/ft_wout_quote_len.c			\
																															\
			signals/ft_default_signals.c			signals/ft_handle_sigint.c			signals/ft_heredoc_sighandler.c		\
			signals/ft_heredoc_signals.c			signals/ft_main_signals.c			signals/ft_signaled.c				\
																															\
			tokens/ft_free_token_list.c				tokens/ft_free_token.c				tokens/ft_get_token_type.c			\
			tokens/ft_init_token.c					tokens/ft_input_split_to_token.c	tokens/ft_isretoken.c				\
			tokens/ft_retoken.c						tokens/ft_token_addback.c			tokens/ft_token_reassign.c			\
			tokens/ft_token_split.c					tokens/ft_tokens_to_pipe.c												\
																															\
			tokens_utils/ft_add_handler.c			tokens_utils/ft_add_to_strs.c		tokens_utils/ft_extract_operator.c	\
			tokens_utils/ft_extract_word.c			tokens_utils/ft_isoperator.c		tokens_utils/ft_operator_len.c		\
			tokens_utils/ft_word_count.c			tokens_utils/ft_word_len.c												

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_DIR = objects

LIBFT_LIB = ./libft

INCLUDE_LFT = ./libft/libft.a

all: $(LIBFT) $(NAME)

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

v:
	make re; clear; valgrind --suppressions=valgrind.supp --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./minishell

$(NAME): $(OBJ)
	@make -C $(LIBFT_LIB)
	@cc $(CFLAGS) $(OBJ) -o $(NAME) -lreadline $(INCLUDE_LFT) 

$(OBJ_DIR)/%.o: ./%.c
	@mkdir -p $(OBJ_DIR) 
	@mkdir -p $(OBJ_DIR)/builtin 
	@mkdir -p $(OBJ_DIR)/builtin_utils
	@mkdir -p $(OBJ_DIR)/env
	@mkdir -p $(OBJ_DIR)/exec
	@mkdir -p $(OBJ_DIR)/fd
	@mkdir -p $(OBJ_DIR)/global
	@mkdir -p $(OBJ_DIR)/libft_utils 
	@mkdir -p $(OBJ_DIR)/nodes
	@mkdir -p $(OBJ_DIR)/parse
	@mkdir -p $(OBJ_DIR)/pipes
	@mkdir -p $(OBJ_DIR)/pipes_utils
	@mkdir -p $(OBJ_DIR)/quotes
	@mkdir -p $(OBJ_DIR)/signals
	@mkdir -p $(OBJ_DIR)/tokens_utils
	@mkdir -p $(OBJ_DIR)/tokens
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJ)
	@rm -fr $(OBJ_DIR)
	@make clean -C ./$(LIBFT_LIB)

fclean: clean
	@make fclean -C libft
	rm -fr minishell

re: fclean all

.PHONY: all clean fclean re
