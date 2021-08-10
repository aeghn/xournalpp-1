/*
 * Xournal++
 *
 * PDF Page GLib Implementation
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <poppler.h>

#include "pdf/base/XojPdfPage.h"


class PopplerGlibPage: public XojPdfPage {
public:
    PopplerGlibPage(PopplerPage* page);
    PopplerGlibPage(const PopplerGlibPage& other);
    virtual ~PopplerGlibPage();
    PopplerGlibPage& operator=(const PopplerGlibPage& other);

public:
    virtual double getWidth();
    virtual double getHeight();

    virtual void render(cairo_t* cr, bool forPrinting = false);  // NOLINT(google-default-arguments)

    virtual std::vector<XojPdfRectangle> findText(std::string& text);

    virtual std::string selectText(XojPdfRectangle* rec);
    virtual std::string selectTextInArea(XojPdfRectangle* rec);
    virtual std::vector<XojPdfRectangle> selectTextRegion(XojPdfRectangle* rec, double scale);
    virtual std::vector<XojPdfRectangle> selectTextRegionInArea(XojPdfRectangle* rec, double scale);

    virtual int getPageId();

private:
    PopplerPage* page;
};
