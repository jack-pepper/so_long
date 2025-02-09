/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_screens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:02:51 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/09 12:29:58 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/*
 * Defines specific screens to be displayed in the console on events.
 */

void	display_start_screen(void)
{
	ft_printf("\033[1;32m");
	ft_printf("         ___     ___     _       ___    _  _    ___     \n");
	ft_printf("  o O O / __|   / _ \\   | |     / _ \\  | \\| |  / __| \n");
	ft_printf(" o      \\_  \\  | (_) |  | |__  | (_) | | .` | | (_ |  \n");
	ft_printf(" TS_[O] |___/   \\___/   |____|  \\___/  |_|\\_|  \\___|\n");
	ft_printf("{=====|_|''''|_|'''''|__|''''|_|'''''|_|''''|_|''''|    \n");
	ft_printf("./o-000'-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-\n");
	ft_printf("\033[0m");
	ft_printf("\n\033[1;34m📜 WELCOME TO PIXEL LAND! 📜\033[0m\n");
	ft_printf("\n");
	ft_printf("A mysterious land full of hidden treasures awaits!\n");
	ft_printf("Collect all the collectibles and find the exit!\n");
	ft_printf("\n");
	ft_printf("\033[1;33m⚠️  Beware! Danger might lurk ");
	ft_printf("around every corner... ⚠️\033[0m\n\n");
	ft_printf("\033[1;36m🎮 GAME CONTROLS 🎮\033[0m\n");
	ft_printf("➡️  Move: Arrow keys or WASD\n");
	ft_printf("🚪 Exit: Find the door after collecting everything!\n");
	ft_printf("❌ Quit: Press 'ESC'\n");
	ft_printf("\n");
	ft_printf("\033[1;32m👾 Developed by: mmalie 42\033[0m\n");
	ft_printf("\nPress any key to start your adventure!\n");
}

void	display_victory_screen(void)
{
	ft_printf("\033[1;34m");
	ft_printf("\n");
	ft_printf("  🎉  🚂 CHAMPION EXPRESS ARRIVES! 🚂  🎉  \n");
	ft_printf("\n");
	ft_printf("           __   __   ___    _   _       \n");
	ft_printf("   o O O   \\ \\ / /  / _ \\  | | | |   \n");
	ft_printf("  o         \\ V /  | (_) | | |_| |     \n");
	ft_printf(" TS__[O]     |_|    \\___/   \\___/     \n");
	ft_printf("{======|___|'''''|_|'''''|_|'''''|=|    \n");
	ft_printf("./o--000' \"`-0-0-'\"`-0-0-'\"`-0-0-'   \n");
	ft_printf("         __      __  ___    _  _        \n");
	ft_printf("   o O O \\ \\    / / |_ _|  | \\| |    \n");
	ft_printf("  o       \\ \\/\\/ /   | |   |    |    \n");
	ft_printf(" TS__[O]   \\_/\\_/   |___|  |_|\\_|    \n");
	ft_printf("{======|___|'''''|_|'''''|_|''''|      \n");
	ft_printf("./o--000'   -0-0-   -0-0-   -0-0-    \n");
	ft_printf("\n");
	ft_printf("✨🏆 CONGRATULATIONS! 🏆✨\n");
	ft_printf("\n");
	ft_printf("\033[1;32m🎉 YOU HAVE CONQUERED PIXEL LAND! 🎉\033[0m\n");
	ft_printf("\n");
	ft_printf("\033[0m");
}

void	display_defeat_screen(void)
{
	ft_printf("\033[1;31m");
	ft_printf("             ___   ___   __  __   ___   \n");
	ft_printf("   o O O    / __| /   \\ |  \\/  | | __|  \n");
	ft_printf("  o        | (_ | | - | | |\\/| | | _|   \n");
	ft_printf(" TS__[O]    \\___| |_|_| |_|__|_| |___|  \n");
	ft_printf("{======|___|''''|_|'''|_|''''''|_|'''| \n");
	ft_printf("./o--000'  -0-0-  -0-0- -0-0-0-  -0-0-   \n");
	ft_printf("              ___    _   _   ___   ___ \n");
	ft_printf("     o O O   / _ \\  \\ \\ / / | __| | _ \\  \n");
	ft_printf("    o       | (_) |  \\ V /  | _|  |   /  \n");
	ft_printf("   TS__[O]   \\___/    \\_/   |___| |_|_\\  \n");
	ft_printf("_{======|___|'''''|_|'''''|_|'''|_|'''|  \n");
	ft_printf("./o--000'    -0-0-'  -0-0-  -0-0- -0-0-'  \n");
	ft_printf("\n");
	ft_printf("             💀 GAME OVER 💀                   \n");
	ft_printf("          ☠️  YOU HAVE LOST! ☠️                \n");
	ft_printf("       Better luck next time, traveler...      \n");
	ft_printf("_________________________________________________\n");
	ft_printf("\033[0m");
}
