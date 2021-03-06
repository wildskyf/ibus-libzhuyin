/* vim:set et ts=4 sts=4:
 *
 * ibus-libzhuyin - New Zhuyin engine based on libzhuyin for IBus
 *
 * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef __ZY_FALLBACK_EDITOR_
#define __ZY_FALLBACK_EDITOR_

#include "ZYText.h"
#include "ZYEditor.h"

namespace ZY {

class FallbackEditor : public Editor {
public:
    FallbackEditor (ZhuyinProperties &props, Config & config)
        : Editor (props, config),
          m_quote (TRUE),
          m_double_quote (TRUE),
          m_prev_committed_char (0) { }

    gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    void reset (void);

    void setPrevCommittedChar (gunichar ch)
    {
        m_prev_committed_char = ch;
    }

private:
    void commit (gchar ch)
    {
        gchar str[2] = {ch, 0};
        StaticText text (str);
        commitText (text);
    }

    void commit (gunichar ch)
    {
        Text text (ch);
        commitText (text);
    }

    void commit (const gchar *str)
    {
        StaticText text (str);
        commitText (text);
    }

    void commit (const String &str)
    {
        commit ((const gchar *)str);
    }

    gboolean processSymbol (guint keyval, guint keycode, guint modifiers);

private:
    gboolean m_quote;
    gboolean m_double_quote;
    gunichar m_prev_committed_char;
    
};

};
#endif
