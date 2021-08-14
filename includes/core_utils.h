#ifndef CORE_UTILS_H
# define CORE_UTILS_H

#include "types.h"

void	ft_free_core(t_core	*core);
void	*ft_malloc_or_exit(int	size);
void	ft_exit_error(t_core *core, t_exit_code exit_code);

#endif // !CORE_UTILS_H
