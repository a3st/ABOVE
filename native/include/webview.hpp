// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

#include "webview.h"

namespace libwebview
{
    class App
    {
      public:
        App(std::string_view const app_name, std::string_view const title, uint32_t const width, uint32_t const height,
            bool const resizeable, bool const debug_mode)
        {
            app = webview_create_app(std::string(app_name).c_str(), std::string(title).c_str(), width, height,
                                     resizeable, debug_mode);
        }

        ~App()
        {
            webview_delete_app(app);
        }

        auto quit() -> void
        {
            webview_quit_app(app);
        }

        auto run(std::string_view const url) -> void
        {
            webview_run_app(app, std::string(url).c_str());
        }

        auto set_size(uint32_t const width, uint32_t const height) -> void
        {
            webview_set_size_app(app, width, height);
        }

        auto set_min_size(uint32_t const width, uint32_t const height) -> void
        {
            webview_set_min_size_app(app, width, height);
        }

        auto set_max_size(uint32_t const width, uint32_t const height) -> void
        {
            webview_set_max_size_app(app, width, height);
        }

        template <typename... Args>
        auto bind(std::string_view const name, std::function<void(Args...)>&& callback)
        {
            // webview_bind(app, std::string(name).c_str(), )
        }

      private:
        C_Webview app;
    };
} // namespace libwebview