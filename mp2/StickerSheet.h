#ifndef STICKERSHEET_H
#define STICKERSHEET_H

#include "Image.h"
using namespace std;    
class StickerSheet{
        public:
            StickerSheet (const Image &picture, unsigned max);
            ~StickerSheet ();
            StickerSheet (const StickerSheet &other);
            const StickerSheet &operator= (const StickerSheet &other);
            void changeMaxStickers (unsigned max);
            int addSticker (Image &sticker, unsigned x, unsigned y);
            bool translate (unsigned index, unsigned x, unsigned y);
            void removeSticker (unsigned index);
            Image *getSticker (unsigned index) const;
            Image render () const;
            void copyHelper(const StickerSheet &other);
            void destroy_();



        private:
            unsigned maxpapushin;
            Image  pants;
            Image * binky;
            unsigned *Xcoordinate;
            unsigned *Ycoordinate;
            unsigned current;
};

#endif


/*
#ifndef STICKER_SHEET_H_
#define STICKER_SHEET_H_

#include "Image.h"

using namespace cs225;

class StickerSheet {
            public:
                            StickerSheet(const Image &picture, unsigned max);
                                    ~StickerSheet();
                                            StickerSheet(const StickerSheet &other);
                                                    const StickerSheet &operator=(const StickerSheet &other);
                                                            void changeMaxStickers(unsigned max);
                                                                    int addSticker(Image &sticker, unsigned x, unsigned y);
                                                                            bool translate(unsigned index, unsigned x, unsigned y);
                                                                                    void removeSticker(unsigned index);
                                                                                            Image* getSticker(unsigned index) const;
                                                                                                    Image render() const;
                                                                                                        private:
                                                                                                            Image* imageList_;      
                                                                                                                    int* xList_;
                                                                                                                            int* yList_;
                                                                                                                                    unsigned max_;
                                                                                                                                            unsigned size_;

                                                                                                                                                    void _copy(StickerSheet const &other);
};

#endif
*/
