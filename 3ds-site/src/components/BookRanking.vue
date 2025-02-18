<script setup lang="ts">
import BookRank from './BookRank.vue'
import { type BookRankProps } from './BookRank.vue'
import { onMounted, ref, watch } from 'vue'
import { useI18n } from 'vue-i18n'
const { t, locale } = useI18n({
  messages: {
    en: {
      book_1: {
        title: 'Paul Keating: the big-picture leader',
        author: 'Tony Bramston',
        rating: '5 Stars',
      },
      book_2: {
        title: 'Bob Hawke: Demons and Destiny',
        author: 'Tony Bramston',
        rating: '5 Stars',
      },
      book_3: {
        title: 'Triumph and Demise The Broken Promise of a Labor Generation: Updated Edition',
        author: 'Paul Kelly',
        rating: '5 Stars',
      },
      book_4: {
        title: 'John Curtin: A Life',
        author: 'David Day',
        rating: '5 Stars',
      },
      book_5: {
        title: 'The Big Fella: Jack Lang and the Australian Labor Party, 1891–1949',
        author: 'Bede Nairn',
        rating: '5 Stars',
      },
      book_6: {
        title: 'Chifley : A Life',
        author: 'David Day',
        rating: '5 Stars',
      },
    },
    kr: {
      book_1: {
        rating: '별5개',
      },
      book_2: {
        rating: '별5개',
      },
      book_3: {
        rating: '별5개',
      },
      book_4: {
        rating: '별5개',
      },
      book_5: {
        rating: '별5개',
      },
      book_6: {
        rating: '별5개',
      },
    },
  },
})

function get_books(): BookRankProps[] {
  return [
    {
      id: 1,
      title: t('book_1.title'),
      author: t('book_1.author'),
      year: 2016,
      picture: '/books/HNI_0002.jpg',
      completed_date: new Date('2024-09-16'),
      rating: t('book_1.rating'),
      isbn: '9781925321746',
    },
    {
      id: 2,
      title: t('book_2.title'),
      author: t('book_2.author'),
      year: 2022,
      picture: '/books/HNI_0003.jpg',
      completed_date: new Date('2024-10-18'),
      rating: t('book_2.rating'),
      isbn: '9780143788096',
    },
    {
      id: 3,
      title: t('book_3.title'),
      author: t('book_3.author'),
      year: 2014,
      picture: '/books/HNI_0004.jpg',
      completed_date: new Date('2024-11-04'),
      rating: t('book_3.rating'),
      isbn: '9780522862102',
    },
    {
      id: 4,
      title: t('book_4.title'),
      author: t('book_4.author'),
      year: 1999,
      picture: '/books/HNI_0006.jpg',
      completed_date: new Date('2024-11-19'),
      rating: t('book_4.rating'),
      isbn: '9780732264130',
    },
    {
      id: 5,
      title: t('book_5.title'),
      author: t('book_5.author'),
      year: 1986,
      picture: '/books/HNI_0005.jpg',
      completed_date: new Date('2024-12-12'),
      rating: t('book_5.rating'),
      isbn: '9781761280740',
    },
    {
      id: 6,
      title: t('book_6.title'),
      author: t('book_6.author'),
      year: 2001,
      picture: '/books/HNI_0007.jpg',
      completed_date: new Date('2025-01-20'),
      rating: t('book_6.rating'),
      isbn: '9781460706169',
    }
  ]
}

const booksSorted = ref<BookRankProps[]>([])

type OrderByTypes = 'read-asc' | 'read-desc' | 'published-asc' | 'published-desc'

const selectedOrderBy = ref<OrderByTypes>('read-desc')

function orderBy(value: OrderByTypes) {
  const books = get_books()
  switch (value) {
    case 'read-asc':
      booksSorted.value = books.sort(
        (a, b) => a.completed_date.getTime() - b.completed_date.getTime(),
      )
      break
    case 'read-desc':
      booksSorted.value = books.sort(
        (a, b) => b.completed_date.getTime() - a.completed_date.getTime(),
      )
      break
    case 'published-asc':
      booksSorted.value = books.sort((a, b) => a.year - b.year)
      break
    case 'published-desc':
      booksSorted.value = books.sort((a, b) => b.year - a.year)
      break
  }
}

watch(locale, () => {
  console.log('locale changed')
  orderBy(selectedOrderBy.value)
})

watch(selectedOrderBy, (value) => {
  orderBy(value)
})

onMounted(() => {
  orderBy(selectedOrderBy.value)
})
</script>

<template>
  <div>
    <select v-model="selectedOrderBy">
      <option value="read-desc">Latest read</option>
      <option value="read-asc">Oldest read</option>
      <option value="published-desc">Latest published</option>
      <option value="published-asc">Oldest published</option>
    </select>
    <BookRank v-for="book in booksSorted" :key="book.title" v-bind="book" />
  </div>
</template>

<style scoped></style>
