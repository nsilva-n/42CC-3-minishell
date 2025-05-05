/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsilva-n <nsilva-n@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:28:27 by nsilva-n          #+#    #+#             */
/*   Updated: 2025/05/05 11:41:42 by nsilva-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <limits.h>
# include <stdarg.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <errno.h>
# include <signal.h>

typedef enum s_tokentype
{
	RED_IN = 1,
	RED_OUT,
	RED_APP,
	HERE_DOC,
	PIPE,
	WORD,
}	t_tokentype;

typedef struct s_pipex
{
	int				pid;
	int				pipe[2];
	int				has_doc;
	int				doc_pipe[2];
	int				out_fd;
	int				in_fd;
	bool			bad_command;
	char			*path;
	char			**red_out;
	char			**red_in;
	char			**cmd;
	struct s_pipex	*next;
	struct s_pipex	*previous;
}					t_pipex;

typedef struct s_token
{
	int				type;
	char			*str;
	int				index;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_index
{
	int	var_i;
	int	new_i;
	int	t_i;
}	t_index;

typedef struct s_command
{
	char	**cmdlist;
	int		cmd_amount;
	int		haspipe;
}			t_command;

typedef struct s_env
{
	char			*var;
	char			*key;
	char			*value;
	bool			exported;
	struct s_env	*prev;
	struct s_env	*next;
}					t_env;

typedef struct s_global
{
	t_token			*token;
	t_command		*cmd;
	t_pipex			*pipes;
	struct s_env	*env;
	char			*pwd;
	int				exit_status;
	bool			signaled;
	char			*input;
	char			*home;
	char			*heredoc_str;
	int				line_nbr;
}					t_global;

void		ft_exit(int exit_code);

// BUILTIN

void		ft_cd(char **args, int fd);
void		ft_echo(char **cmd, int fd);
bool		ft_env(t_env *env, char **args, int fd);
void		ft_exit_builtin(char **args);
void		ft_export(char **args, int fd, bool flag);
void		ft_pwd(int fd);
void		ft_unset(char **str, t_env *env);

// BUILTIN_UTILS

void		ft_export_rec(t_env *temp, int fd);
bool		ft_isbuiltin(t_pipex *pipes);
bool		ft_isflagn(char *str);
bool		ft_isnext(t_env *temp, int grade);
bool		ft_isvalidexport(char *str);
void		ft_update_pwd(void);

// ENV

char		**ft_env_to_strs(t_env *env);
bool		ft_error_env(char *str, int err, int fd);
void		ft_free_env(t_env *env);
t_env		*ft_get_env(char **envp);
t_env		*ft_init_mini_env(void);

// EXEC

char		*ft_access(char **all_paths, char **split_cmd);
void		ft_error_execve(char *cmd);
void		ft_exec_builtin(t_pipex *pipes);
bool		ft_exec_single_cmd(t_pipex *pipes);
void		ft_execute(char *path, t_pipex *pipes, char **envp);
char		*ft_get_path(char *cmd, char **env);
bool		ft_isbadcommand(t_pipex *pipes);
bool		ft_main_exec(t_pipex *pipes);

// FD

void		ft_close_cmd_fds(t_pipex *pipes);
void		ft_close_fds(int *fds);
void		ft_close(int fd);
bool		ft_error_redir(t_token *token);
char		*ft_heredoc_expand(char *str);
void		ft_input_redir(t_pipex *pipes);
bool		ft_isfinaldoc(t_pipex *pipes);
bool		ft_isloopdoc(t_pipex *pipes);
char		*ft_last_heredoc(t_token *token);
bool		ft_open_app_out(char *str, t_pipex *pipes);
bool		ft_open_doc(char *str, t_pipex *pipes);
bool		ft_open_in_files_loop(t_pipex *pipes);
bool		ft_open_input_file(char *str, t_pipex *pipes);
bool		ft_open_std_out(char *str, t_pipex *pipes);
void		ft_output_redir(t_pipex *pipes);
char		*ft_process_heredoc(char *help, char *tmp);
bool		ft_rep_in_redir(t_pipex *pipes);
bool		ft_rep_out_redir(t_pipex *pipes);
void		ft_rl_to_doc(char *eof, t_pipex *pipes);
void		ft_signal_exit(char *help, char *eof, t_pipex *pipes);
void		close_fds(void);

// GLOBAL

bool		ft_error(char *str, int err);
void		ft_free(void);
char		*ft_get_home(void);
pid_t		ft_get_pid(void);
void		ft_init_global(char **env);
t_global	*glob(void);

// LIBFT_UTILS

long long	ft_atoll(const char *nptr);
void		ft_free_strs(char **strs);
bool		ft_isdquote(char c);
bool		is_in_long_long_range(char *str);
bool		ft_isnumber(const char *str);
bool		ft_isquote(char c);
bool		ft_isspace(char c);
bool		ft_issquote(char c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strjoin_gnl(char *s1, char const *s2);
int			ft_strs_count(char **strs);

// NODES

int			ft_count_node(t_env *env);
void		ft_expand_node(t_token *token, char *var);
void		ft_free_node(t_env *node);
char		*ft_get_node_key(t_token *token);
char		*ft_get_node_value(t_env *env, char *key);
char		*ft_get_special_node(char *key);
t_env		*ft_init_node(char *str);
bool		ft_isnode(t_env *node, t_env *new);
void		ft_node_addback(t_env *node, t_env *add, bool flag);
int			ft_node_key_len(char *key, int i);
void		ft_remove_node(char *str);

// PARSE

void		ft_expand_nodes(t_token *start, int flag);
void		ft_expand_tilde(t_token *token);
void		ft_expand(t_token *token);
int			ft_expanded_len(t_token *t, char *var_value);
void		ft_free_command(void);
void		ft_free_new_input(char *new_input);
void		ft_hide_expand(char *str);
void		ft_init_index(t_index *i);
bool		ft_isexpandneeded(t_token *token);
bool		ft_isspecialexpand(char *key);
bool		ft_main_parse(void);
void		ft_tilde_loop(t_token *token);
void		ft_unhide_expand(char *str);

//PIPES

void		ft_child_process(t_pipex *pipes);
void		ft_fill_pipes(t_token *token, t_pipex *start);
void		ft_free_pipe_list(t_pipex *pipes);
t_pipex		*ft_get_pipe_list(t_token *token);
t_pipex		*ft_init_pipe(void);
bool		ft_isvalidpipe(t_token *token);
bool		ft_new_child(t_pipex *pipes);
void		ft_pipe_addback(t_pipex *pipes, t_pipex *add);
int			ft_pipe_count(t_token *token);

// PIPES_UTILS

bool		ft_isvalidfirstparse(t_token *token);
bool		ft_isvalidredir(t_token *token);
void		ft_waitpid(int pid);

// QUOTES

void		ft_copy_woutquote(char *dest, char *src);
bool		ft_isinquote(const char *input, int index, bool flag);
int			ft_quoted_len(char *str, int i);
void		ft_remove_pipe_quotes(t_pipex *pipes);
char		*ft_remove_quotes(char *str);
size_t		ft_wout_quote_len(char *str);

// SIGNALS

void		ft_default_signals(void);
void		ft_handle_sigint(int sig);
void		ft_heredoc_signals(void);
void		ft_heredoc_sighandler(int sig);
void		ft_main_signals(void);
void		ft_signaled(int status);

// TOKEN_UTILS

char		**ft_add_handler(char **words, char *word, char *prefix);
char		**ft_add_to_strs(char **words, char *word);
t_token		*ft_extract_operator(t_token *t);
t_token		*ft_extract_word(t_token *token);
bool		ft_isoperator(char *str, int i);
int			ft_operator_len(char *str, int i);
int			ft_word_count(char const *s);
int			ft_word_len(char *s);

// TOKEN

void		ft_free_token_list(t_token *token);
void		ft_free_token(t_token *token);
int			ft_get_token_type(char *str);
t_token		*ft_init_token(char *str);
t_token		*ft_input_split_to_token(char **words);
bool		ft_isretoken(char *str);
t_token		*ft_retoken(t_token *token);
void		ft_token_addback(t_token *token, t_token *add);
t_token		*ft_token_reassign(t_token *token);
char		**ft_token_split(char const *str);
void		ft_tokens_to_pipe(t_token *token);

#endif