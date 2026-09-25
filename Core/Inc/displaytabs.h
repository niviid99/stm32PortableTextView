#ifndef DISPLAYTABS_H
#define DISPLAYTABS_H

#include "fonts.h"
#include "st7789.h"

typedef struct
{
  const char ***tabs;
  uint16_t tabs_count;
  uint16_t current_tab;
} Tabs_t;

static inline void tabs_change(Tabs_t *tabs, uint16_t tab)
{
  if (tab < tabs->tabs_count && tab >= 0)
  {
    tabs->current_tab = tab;
  }
}

static inline void tabs_next(Tabs_t *tabs)
{
  tabs->current_tab++;
  if (tabs->current_tab >= tabs->tabs_count)
  {
    tabs->current_tab = 0;
  }
}

static inline void tabs_draw(Tabs_t *tabs)
{
  ST7789_Fill_Color(BLACK);
  const char **ptr = tabs->tabs[tabs->current_tab];
  for (unsigned int i = 0; ptr[i] != NULL; i++)
  {
    ST7789_WriteString(0, i * 20, ptr[i], Font_7x10, WHITE, BLACK);
  }
}

#endif